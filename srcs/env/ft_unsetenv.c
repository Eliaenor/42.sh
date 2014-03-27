/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 06:23:34 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

static int	del_to_env(t_data *st, char *pattern)
{
	int			i;

	i = 0;
	while (st->envtab[i])
	{
		if (!ft_strncmp(st->envtab[i], pattern, ft_strlen(pattern)) &&
			st->envtab[i][ft_strlen(pattern)] == '=')
		{
			i++;
			while (st->envtab[i])
			{
				st->envtab[i - 1] = st->envtab[i];
				i++;
			}
			st->envtab[i - 1] = NULL;
			break ;
		}
		i++;
	}
	return (0);
}

int			sh_unsetenv(t_data *st)
{
	int			i;

	i = 0;
	while (st->cmd[i])
		i++;
	if (i > 2)
		return (!write(2, "unsetenv: too many arguments.\n", 43));
	i = 1;
	while (st->cmd[i])
		del_to_env(st, st->cmd[i++]);
	return (1);
}
