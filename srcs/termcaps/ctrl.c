/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 21:14:17 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

int		ft_ctrl(t_data *st, char *buff, int j)
{
	char	stdin[3];

	read(1, &stdin, 3);
	if (stdin[0] == 59 && stdin[1] == 53)
	{
		if (stdin[2] == 68)
			j = goto_prevword(buff, j, st);
		if (stdin[2] == 67)
			j = goto_nextword(buff, j, st);
	}
	return (j);
}

int		goto_nextword(char *buff, int j, t_data *st)
{
	while (buff[j] != ' ' && buff[j] != '\0')
		j = right_arrow(j, buff, st);
	while (buff[j] == ' ' && buff[j] != '\0')
		j = right_arrow(j, buff, st);
	return (j);
}

int		goto_prevword(char *buff, int j, t_data *st)
{
	if (j != 0 && buff[j - 1] == ' ')
	{
		while (buff[j] != ' ' && j != 0)
			j = left_arrow(j);
	}
	while (buff[j] == ' ' && j != 0)
		j = left_arrow(j);
	while (buff[j] != ' ' && j != 0)
		j = left_arrow(j);
	if (j != 0)
		j = right_arrow(j, buff, st);
	return (j);
}
