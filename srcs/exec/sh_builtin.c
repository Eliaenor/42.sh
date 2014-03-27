/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srieu-si <srieu-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 18:36:47 by srieu-si          #+#    #+#             */
/*   Updated: 2014/03/25 19:31:14 by srieu-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/ftsh.h"

int		select_builtin(t_data *st)
{
	int		i;
	int		success_cmd;
	int		(*t_parse[6])(t_data *st);
	char	*tab_builtin[6] =
	{"exit", "env", "setenv", "unsetenv", "cd", "echo"};

	t_parse[0] = &sh_exit;
	t_parse[1] = &sh_env;
	t_parse[2] = &sh_setenv;
	t_parse[3] = &sh_unsetenv;
	t_parse[4] = &sh_cd;
	t_parse[5] = &sh_echo;
	i = -1;
	success_cmd = 0;
	while (i++ < 5)
	{
		if (ft_strcmp(tab_builtin[i], st->cmd[0]) == 0)
		{
			t_parse[i](st);
			success_cmd = 1;
			i = 6;
		}
	}
	return (success_cmd);
}

int		sh_call_op(t_data *st, t_parse *node)
{
	int		success_op;
	int		i;
	int		(*call_op[7])(t_data *st, t_parse *node);
	char	*tab_operat[7] =
	{";", "&&", "||", "|", ">>", ">", "<"};

	call_op[0] = &sh_sem;
	call_op[1] = &sh_and;
	call_op[2] = &sh_or;
	call_op[3] = &sh_pipe;
	call_op[4] = &sh_redir_dbright;
	call_op[5] = &sh_redir_right;
	call_op[6] = &sh_redir_left;
	i = -1;
	success_op = 0;
	while (i++ < 6)
	{
		if (ft_strcmp(tab_operat[i], st->cmd[0]) == 0)
		{
			call_op[i](st, node);
			success_op = 1;
		}
	}
	return (success_op);
}

