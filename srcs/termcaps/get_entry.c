/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 21:11:40 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <termios.h>
#include <term.h>

int		ft_get_entry(t_data *st)
{
	char	*buff;
	int		j;

	j = 0;
	buff = (char *)malloc(sizeof(char) * 262145);
	buff[262144] = '\0';
	ft_bzero(buff, 262144);
	st->linelen = 1;
	st->reset = 0;
	st->incmd = 0;
	ft_init_global(st);
	init_term(st);
	ft_prompt(st);
	if (ft_test(st, buff, j) == -1)
		return (-1);
	reset_term(st);
	st->incmd = 1;
	return (1);
}

int		ft_test(t_data *st, char *buff, int j)
{
	char	stdin[3];

	ft_bzero(stdin, 3);
	while (read(1, &stdin, 3))
	{
		if (st->reset == 1)
		{
			st->reset = 0;
			j = 0;
			ft_bzero(buff, ft_strlen(buff));
		}
		if (stdin[0] >= 32)
			buff = ft_test3(st, buff, &j, stdin);
		else if (stdin[0] == 9)
			j = tab_key(st, &buff, j);
		else if (stdin[0] == 27 || stdin[0] == 10)
		{
			j = ft_test2(st, buff, j, stdin);
			if (j < 0)
				return (j);
		}
		ft_bzero(stdin, 3);
	}
	return (0);
}

int		ft_test2(t_data *st, char *buff, int j, char *stdin)
{
	if (stdin[0] == 27)
	{
		if ((j = escape_key(st, buff, j, stdin)) == -1)
			return (-1);
	}
	else
	{
		lseek(st->fd_history, -1, SEEK_END);
		st->history_last = 0;
		enter_key(st, buff);
		return (-2);
	}
	return (j);
}

char	*ft_test3(t_data *st, char *buff, int *j, char *stdin)
{
	if ((stdin[0] >= 32 && stdin[0] < 127) && stdin[1] == 0)
	{
		st->history_last = 0;
		buff = ascii_key(st, buff, stdin, *j);
		(*j)++;
	}
	else if (stdin[0] == 127)
	{
		if (buff[0] != '\0' && *j != 0)
		{
			delete_cmd(st, *j);
			buff = ft_delete(*j, buff);
			ft_putstr_term(buff, st);
			back_to_j(buff, (*j) - 2);
			(*j)--;
		}
	}
	return (buff);
}
