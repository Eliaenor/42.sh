/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agreau <agreau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 22:07:55 by agreau            #+#    #+#             */
/*   Updated: 2014/03/27 08:19:13 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
/*
 *@fn				add_to_lex(t_data *st, char *item)
 *@brief			fonction for add link to lexer
 *@param[out] 		st		struct of storage for all stuff of shell
 *@param[out] 		item	part of cmd to add
 *@param[in]		new		new link
 *@param[in]		ope		1 if link contains a valid operator else 0
 *@param[in]		val 	value of link
 *@param[in]		next 	link to next link
 *@param[in]		prev 	link to previous link
 */
void	add_to_lex(t_data *st, char *item, int init)
{
	t_lex	*new_e;
	t_lex	*lex;

	lex = st->lex;
	ft_strtrim(item);
	if (init == 0)
		init_lexer(st, item);
	else
	{
		while (lex->next != NULL)
			lex = lex->next;
		if ((new_e = (t_lex *)malloc(sizeof(t_lex))))
		{
			new_e->ope = is_valid_operator(item);
			new_e->val = item;
			new_e->prev = lex;
			new_e->next = NULL;
			lex->next = new_e;\
		}
	}
}

void	init_lexer(t_data *st, char *item)
{
	st->lex = (t_lex *)malloc(sizeof(t_lex));
	if (st->lex != NULL)
	{
		st->lex->ope = is_valid_operator(item);
		st->lex->val = item;
		st->lex->prev = NULL;
		st->lex->next = NULL;
	}
}

int		is_space_or_tab(char c)
{
	return (c == 23 || c == 32);
}

/*
*@fn			sh_lexing(t_data *st)
*@brief			function for cut entry cmd in a link
*@param[out]	st			struct of storage for all stuff of shell
*@param[in]		i			counter
*@param[in]		len_cmd		length of cmd
*@param[in]		ST_LINE		call of((*st).line) entry process
*/
void	sh_lexing(t_data *st)
{
	int		i;
	int		len_cmd;
	int		init;
	int		len_op;

	i = 0;
	len_cmd = 0;
	len_op = 0;
	init = 0;
	while (st->line[i] != '\0')
	{
		if (is_space_or_tab(st->line[i]))
			i++;
		while (st->line[i] && detect_ope(st->line[i]) == 1)
		{
			len_cmd++;
			i++;
		}
		if (len_cmd > 0)
		{
			add_to_lex(st, ft_strsub(st->line, i - len_cmd, len_cmd), init);
			init = 1;
			len_cmd = 0;
		}
		while (st->line[i] && detect_ope(st->line[i]) == -1)
		{
			len_op++;
			i++;
		}
		if (len_op > 0)
		{
			add_to_lex(st, ft_strsub(st->line, i - len_op, len_op), init);
			init = 1;
			len_op = 0;
		}
	}
}
