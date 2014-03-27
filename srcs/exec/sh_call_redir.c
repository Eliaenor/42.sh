/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_call_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srieu-si <srieu-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 01:51:47 by srieu-si          #+#    #+#             */
/*   Updated: 2014/03/27 01:51:49 by srieu-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

int		sh_redir_left(t_data *st, t_parse *node)
{
	pid_t	father;
	int		file;
	int		ret;

	father = fork();
	if (father)
		waitpid(father, &ret, 0);
	else
	{
		if ((file = open(node->right->val, O_RDONLY)) != -1)
		{
			dup2(file, 0);
			if (!st->cmd[1] && node->right->range == -1)
				st->cmd[1] = node->right->val;
			ret = sh_cmd_exec(st, node->left);
		}
		else
		{
			ft_putendl(ERR_ARG_EXIST);
			ret = 0;
		}
		exit(ret);
	}
	return (ret);
}

int		sh_redir_right(t_data *st, t_parse *node)
{
	pid_t	father;
	int		file;
	int		ret;

	father = fork();
	if (father)
		waitpid(father, &ret, 0);
	else
	{
		if ((file = open(node->right->val, O_WRONLY | O_CREAT | O_TRUNC,
			0644)) != -1)
		{
			dup2(file, 1);
			if (!st->cmd[1] && node->right->range == -1)
				st->cmd[1] = node->right->val;
			ret = sh_cmd_exec(st, node->left);
		}
		else
		{
			ft_putendl(ERR_ARG_EXIST);
			ret = 0;
		}
		exit(ret);
	}
	return (ret);
}

int		sh_redir_dbright(t_data *st, t_parse *node)
{
	pid_t	father;
	int		file;
	int		ret;

	father = fork();
	if (father)
		waitpid(father, &ret, 0);
	else
	{
		if ((file = open(node->right->val, O_WRONLY | O_CREAT | O_APPEND,
			0644)) != -1)
		{
			dup2(file, 1);
			if (!st->cmd[1] && node->right->range == -1)
				st->cmd[1] = node->right->val;
			ret = sh_cmd_exec(st, node->left);
		}
		else
		{
			ft_putendl(ERR_ARG_EXIST);
			ret = 0;
		}
		exit(ret);
	}
	return (ret);
}
