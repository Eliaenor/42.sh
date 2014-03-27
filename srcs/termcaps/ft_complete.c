/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 21:42:46 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <term.h>

int		comp_left_arrow(int j)
{
	if (j == 0)
		return (j);
	tputs(tgetstr("le", NULL), 1, ft_outc);
	return (j - 1);
}

int		comp_right_arrow(int j, char *buff, t_data *st)
{
	char	*term_name;
	int		tmp;

	term_name = ft_getenv(st->envtab, "TERM");
	if (term_name == NULL)
		term_name = "xterm-256color";
	tgetent(NULL, term_name);
	if (j == (int)ft_strlen(buff))
		return (j);
	if ((j + 2) % (tgetnum("co") - 1) == 0)
	{
		tputs(tgetstr("do", NULL), 1, ft_outc);
		tmp = tgetnum("co");
		while (tmp != 1)
		{
			tputs(tgetstr("le", NULL), 1, ft_outc);
			tmp--;
		}
	}
	else
		tputs(tgetstr("nd", NULL), 1, ft_outc);
	return (j + 1);
}

char	*func1(t_data *st, int *i, char *newbuff, char *stdin)
{
	if (stdin[0] == 127)
	{
		if (newbuff[0] != '\0' && *i != 0)
		{
			delete_cmd(st, *i);
			newbuff = ft_delete(*i, newbuff);
			ft_putstr_complete(newbuff, st);
			back_to_j(newbuff, (*i) - 2);
			(*i)--;
		}
	}
	else
	{
		delete_cmd(st, *i);
		newbuff = add_to_tab(newbuff, stdin[0], *i);
		ft_putstr_complete(newbuff, st);
		back_to_j(newbuff, *i);
		(*i)++;
	}
	return (newbuff);
}

int		func2(t_data *st, int i, char *newbuff, char *stdin)
{
	if (stdin[2] == 68)
		i = comp_left_arrow(i);
	else if (stdin[2] == 67)
		i = comp_right_arrow(i, newbuff, st);
	return (i);
}

char	*bell_for_tab(char *buff, int j)
{
	if (j >= 2 && ((buff[j - 1] == ' ' && buff[j - 2] != ' ') ||
		(buff[j - 1] == '\t' && buff[j - 2] != '\t')))
		return ("\0");
	else
	{
		tputs(tgetstr("bl", NULL), 0, ft_outc);
		return (NULL);
	}
}
