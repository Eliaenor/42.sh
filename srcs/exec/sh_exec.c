/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srieu-si <srieu-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 17:29:35 by srieu-si          #+#    #+#             */
/*   Updated: 2014/03/25 19:34:45 by srieu-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

void	sh_split_cmd(t_data *st, t_parse *node)
{
	int	i;

	i = 0;
	while (node->val[i])
	{
		if (node->val[i] == '	')
			node->val[i] = ' ';
		i++;
	}
	st->cmd = ft_strsplit(node->val, ' ');
}

int		sh_cmd_exec(t_data *st, t_parse *node)
{
	int		success_cmd;
	int		ret;

	ret = 0;
	if (node->val != NULL)
	{
		sh_split_cmd(st, node);
		if (node->range == -1)
		{
			if (!(success_cmd = select_builtin(st)))
				ret = sh_isnobuiltin(st);
		}
		else
			sh_call_op(st, node);
	}
	if (!(st->bina))
		free(st->bina);
	if (!(st->cmd))
		free(st->cmd);
	return (ret);
}
