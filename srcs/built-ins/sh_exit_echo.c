/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 01:41:28 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:41:32 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <term.h>

static int		ft_isnumber(char *str)
{
	int		i;
	int		test;

	i = 0;
	test = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			test++;
		i++;
	}
	if ((int)ft_strlen(str) == test)
		return (1);
	else
		return (0);
}

int				sh_exit(t_data *st)
{
	if (st->cmd[1] && ft_isnumber(st->cmd[1]) == 0)
	{
		ft_putendl("42sh: exit: numeric argument required\n");
		return (1);
	}
	else if (st->cmd[1] && st->cmd[2])
	{
		ft_putendl("42sh: exit: too many arguments\n");
		return (1);
	}
	else
	{
		ft_printincolor(EXIT1, RED);
		ft_printincolor(EXIT2, RED);
		reset_term(st);
		tputs(tgetstr("ei", NULL), 0, ft_outc);
		if (st->cmd[1])
			exit(ft_atoi(st->cmd[1]));
		exit(0);
	}
	return (1);
}

int				sh_echo(t_data *st)
{
	int			i;

	i = 1;
	while (st->cmd[i])
	{
		if (i != 1)
			ft_putstr(" ");
		ft_putstr(st->cmd[i++]);
	}
	ft_putchar('\n');
	return (0);
}
