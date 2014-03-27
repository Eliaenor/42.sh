/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 20:55:50 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <term.h>

int		arrow_key(t_data *st, char *buff, int j, char *stdin)
{
	if (stdin[2] == 65)
	{
		j = up_arrow(st, j, buff);
		ft_putstr_term(buff, st);
	}
	else if (stdin[2] == 66)
	{
		j = down_arrow(st, j, buff);
		ft_putstr_term(buff, st);
	}
	if (stdin[2] == 68)
		j = left_arrow(j);
	else if (stdin[2] == 67)
		j = right_arrow(j, buff, st);
	return (j);
}

int		up_arrow(t_data *st, int j, char *buff)
{
	char	*cmd;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(buff);
	delete_cmd(st, len);
	j = 0;
	if (st->history_last == 1 && len)
		get_prev_line(st->fd_history, st);
	st->history_last = 2;
	if ((cmd = get_prev_line(st->fd_history, st)) == NULL)
		return (len);
	ft_strclr(buff);
	while (cmd[i] != '\0')
	{
		buff[j] = cmd[i];
		i++;
		j++;
	}
	buff[j] = '\0';
	return (j);
}

int		down_arrow(t_data *st, int j, char *buff)
{
	char	*cmd;
	int		i;

	i = 0;
	delete_cmd(st, j);
	j = 0;
	if (st->history_last == 2)
		get_next_line_m(st->fd_history);
	st->first_history = 0;
	st->history_last = 1;
	if ((cmd = get_next_line_m(st->fd_history)) == NULL)
		return (0);
	ft_strclr(buff);
	while (cmd[i] != '\0')
	{
		buff[j] = cmd[i];
		i++;
		j++;
	}
	buff[j] = '\0';
	return (j);
}

int		left_arrow(int j)
{
	if (j == 0)
		return (j);
	tputs(tgetstr("le", NULL), 1, ft_outc);
	return (j - 1);
}

int		right_arrow(int j, char *buff, t_data *st)
{
	char	*term_name;

	term_name = ft_getenv(st->envtab, "TERM");
	if (term_name == NULL)
		term_name = "xterm-256color";
	tgetent(NULL, term_name);
	if (j == (int)ft_strlen(buff))
		return (j);
	if ((st->plen + j + 1) % tgetnum("co") == 0)
	{
		tputs(tgetstr("cr", NULL), 1, ft_outc);
		tputs(tgetstr("do", NULL), 1, ft_outc);
	}
	else
		tputs(tgetstr("nd", NULL), 1, ft_outc);
	return (j + 1);
}
