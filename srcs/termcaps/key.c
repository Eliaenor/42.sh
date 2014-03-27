/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 21:16:05 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <term.h>

char	*ascii_key(t_data *st, char *buff, char *stdin, int j)
{
	tputs(tgetstr("im", NULL), 1, ft_outc);
	delete_cmd(st, j);
	buff = add_to_tab(buff, stdin[0], j);
	ft_putstr_term(buff, st);
	back_to_j(buff, j);
	return (buff);
}

int		escape_key(t_data *st, char *buff, int j, char *stdin)
{
	if (stdin[1] == 91)
	{
		if (stdin[2] == 49)
			return ((j = ft_ctrl(st, buff, j)));
		else if (stdin[2] == 72)
			ft_putstr_fd("Home\n", 2);
		else if (stdin[2] == 70)
			ft_putstr_fd("End\n", 2);
		else
			return ((j = arrow_key(st, buff, j, stdin)));
	}
	return (j);
}

int		ft_mini_enter(t_data *st, char *buff)
{
	lseek(st->fd_history, 0, SEEK_END);
	if (ft_strcmp(buff, ""))
	{
		ft_putstr_fd(buff, st->fd_history);
		ft_putchar_fd('\n', st->fd_history);
	}
	st->line = ft_strdup(buff);
	free(buff);
	return (0);
}

int		enter_key(t_data *st, char *buff)
{
	reset_term(st);
	lseek(st->fd_history, -1, SEEK_END);
	st->history_last = 0;
	if (buff[0] == '\0')
	{
		ft_putchar('\n');
		st->line = NULL;
		init_term(st);
		return (0);
	}
	buff = ft_scan_buff(buff, st);
	ft_mini_enter(st, buff);
	reset_term(st);
	ft_putchar('\n');
	return (0);
}
