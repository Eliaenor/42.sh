/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 21:15:04 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <term.h>

char	*ft_delete(int j, char *buff)
{
	char	*new;
	int		i;
	int		k;

	i = 0;
	k = 0;
	new = malloc(ft_strlen(buff));
	while (buff[k] != '\0')
	{
		if (i == j - 1)
			k++;
		new[i++] = buff[k++];
	}
	new[i] = '\0';
	return (new);
}

int		delete_cmd(t_data *st, int j)
{
	int		curent_line;
	char	*term_name;
	int		total_len;

	term_name = ft_getenv(st->envtab, "TERM");
	if (term_name == NULL)
		term_name = "xterm-256color";
	tgetent(NULL, term_name);
	total_len = st->plen + j;
	curent_line = (total_len / (tgetnum("co") + 1)) + 1;
	ft_del_line(st, curent_line);
	while (j + st->plen >= 1)
	{
		j--;
		tputs(tgetstr("le", NULL), 0, ft_outc);
	}
	return (j);
}

int		back_to_j(char *buff, int j)
{
	int		i;

	i = ft_strlen(buff) - j;
	while (i > 1)
	{
		tputs(tgetstr("le", NULL), 0, ft_outc);
		i--;
	}
	return (j);
}

int		ft_del_line(t_data *st, int curent_line)
{
	while (st->linelen > curent_line)
	{
		curent_line++;
		tputs(tgetstr("do", NULL), 0, ft_outc);
	}
	while (st->linelen != 0)
	{
		tputs(tgetstr("dl", NULL), 1, ft_outc);
		tputs(tgetstr("up", NULL), 0, ft_outc);
		st->linelen--;
	}
	tputs(tgetstr("do", NULL), 0, ft_outc);
	return (0);
}
