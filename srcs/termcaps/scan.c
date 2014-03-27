/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 16:34:43 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <term.h>

char	*ft_scan_buff(char *buff, t_data *st)
{
	int		i;
	char	first;
	char	last;

	i = 0;
	first = '\0';
	last = '\0';
	while (buff[i] != '\0')
	{
		if (buff[i] == '\'' && first == '\0')
			first = buff[i];
		else if (buff[i] == '\"' && first == '\0')
			first = buff[i];
		else if (buff[i] == '\"' || buff[i] == '\'')
			last = buff[i];
		i++;
	}
	if (first != '\0' && first != last)
		buff = ft_seek_symbol(buff, st);
	return (buff);
}

char	ft_first_symbol(int j, int k)
{
	if (j == 1 && k == 0)
		return ('\'');
	else if (j == 0 && k == 1)
		return ('\"');
	else
		return ('\0');
}

char	*ft_seek_symbol(char *buff, t_data *st)
{
	char	stdin[3];
	char	*newbuff;
	int		i;

	ft_bzero(stdin, 3);
	i = 0;
	newbuff = (char *)malloc(sizeof(char));
	newbuff[i] = '\0';
	buff = add_to_tab(buff, '\n', ft_strlen(buff));
	tputs(tgetstr("cr", NULL), 0, ft_outc);
	ft_putstr_fd("\n> ", isatty(1));
	init_term(st);
	while (read(1, &stdin, 3))
	{
		if (stdin[0] == 10)
			return (ft_scan_buff(ft_strjoin(buff, newbuff), st));
		else if (stdin[0] >= 32 && stdin[1] == 0)
			newbuff = func1(st, &i, newbuff, stdin);
		else if (stdin[0] == 27 && stdin[1] == 91)
			i = func2(st, i, newbuff, stdin);
		ft_bzero(stdin, 3);
	}
	return (buff);
}
