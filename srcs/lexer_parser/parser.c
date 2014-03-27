/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agreau <agreau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 05:03:01 by agreau            #+#    #+#             */
/*   Updated: 2014/03/27 08:19:19 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

void		init_parse(t_data *st, char *str, int id, int range)
{
	st->parse = (t_parse *)malloc(sizeof(t_parse));
	if (st->parse != NULL)
	{
		st->parse->id = id;
		st->parse->range = range;
		st->parse->val = str;
		st->parse->father = NULL;
		st->parse->right = NULL;
		st->parse->left = NULL;
	}
}

t_parse		*create_node(char *str, int id, int range, t_parse *father)
{
	t_parse *node;

	node = (t_parse *)malloc(sizeof(t_parse));
	if (node != NULL)
	{
		node->id = id;
		node->range = range;
		node->val = str;
		node->father = father;
		node->right = NULL;
		node->left = NULL;
	}
	return (node);
}

t_parse		*copy_tree(t_parse *node, t_parse *tmp_tree, int count)
{
	t_parse *node_tmp;

	if (count == 0)
	{
		tmp_tree = (t_parse *)malloc(sizeof(*tmp_tree));
		if (tmp_tree != NULL)
		{
			tmp_tree->id = node->id;
			tmp_tree->range = node->range;
			tmp_tree->val = node->val;
			tmp_tree->father = NULL;
			tmp_tree->right = node->right;
			tmp_tree->left = node->left;
			count = 1;
		}
	}
	else
	{
		node_tmp = create_node(node->val, node->id, node->range, node->father);
		node_tmp->right = node->right;
		node_tmp->left = node->left;
	}
	if (node->right != NULL)
		tmp_tree = copy_tree(node->right, tmp_tree, count);
	if (node->left != NULL)
		tmp_tree = copy_tree(node->left, tmp_tree, count);
	return (tmp_tree);
}

void		sh_parsing(t_data *st)
{
	t_lex		*lex;
	t_parse		*node;
	t_parse		*current_node;
	t_parse		*ref_node;
	t_parse		*tmp_tree;
	int			id;
	int			range;
	int			ref_ope;

	lex = st->lex;
	id = 1;
	ref_ope = -1;
	while (lex)
	{
		range = is_valid_operator(lex->val);
		if (id == 1)
		{
			init_parse(st, lex->val, id, range);
			ref_node = st->parse;
		}
		else
		{
			current_node = st->parse;
			if (range > -1 && range < ref_ope)
			{
				tmp_tree = copy_tree(st->parse, tmp_tree, 0);
				free(st->parse);
				init_parse(st, lex->val, id, range);
				current_node = st->parse;
				current_node->left = tmp_tree;
				ref_node = st->parse;
			}
			else
			{
				if (range < ref_node->range && current_node->range != range)
				{
					while (current_node->right != NULL)
						current_node = current_node->right;
					node = create_node(lex->val, id, range, current_node);
					current_node->right = node;
					if (ref_node->right->range > -1)
						ref_node = node;
					else
					{
						if (ref_node->right != NULL)
							ref_node->right->father = current_node;
						if (ref_node->left != NULL)
							ref_node->left->father = current_node;
					}
				}
				else if (range > ref_node->range && current_node->range != range)
				{
					node = create_node(ref_node->val, ref_node->id, ref_node->range, current_node);
					ref_node->id = id;
					ref_node->range = range;
					ref_node->val = lex->val;
					ref_node->father = (!ref_node->father) ? NULL : current_node;
					ref_node->left = node;
					ref_node->right = NULL;
				}
				else if (current_node->range == range)
				{
					while (current_node->right != NULL)
						current_node = current_node->right;
					node = create_node(lex->val, id, range, current_node);
					current_node->right = node;
					if (node->range > -1 && node->father->range == -1)
						ref_node = node;
					else
					{
						if (ref_node->right != NULL)
							ref_node->right->father = current_node;
						if (ref_node->left != NULL)
							ref_node->left->father = current_node;
					}
				}
				if (ref_node->right != NULL && ref_node->left != NULL)
					ref_node = ref_node->right;
			}
		}
		id++;
		if (id > 1)
			ref_ope = (range > ref_ope && range > -1) ? range : ref_ope;
		else
			ref_ope = (range < ref_ope && range > -1) ? range : ref_ope;
		lex = lex->next;
	}
}
