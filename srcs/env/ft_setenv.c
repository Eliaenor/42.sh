/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 16:16:46 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

static int		add_env(char *line, t_data *st)
{
	int		i;
	char	**newenv;

	i = 0;
	if (!(newenv = (char**)malloc(sizeof(char*) * (ft_tablen(st->envtab) + 1))))
		return (0);
	while (st->envtab[i])
	{
		newenv[i] = ft_strdup(st->envtab[i]);
		i++;
	}
	newenv[i++] = ft_strdup(line);
	newenv[i] = NULL;
	st->envtab = newenv;
	return (1);
}

static char		**check_env(char *line, t_data *st)
{
	int		i;

	i = 0;
	while (st->envtab[i])
	{
		if (ft_strncmp(st->envtab[i], line, ft_strchr(line, '=') - line) == 0)
			return (st->envtab + i);
		i++;
	}
	return (NULL);
}

int				set_var_env(t_data *st, char *line)
{
	char	**envtmp;

	if (!ft_strchr(line, '='))
		return (1);
	if (!(envtmp = check_env(line, st)))
	{
		if (!add_env(line, st))
			return (0);
	}
	else
		*check_env(line, st) = ft_strdup(line);
	return (0);
}

int				sh_setenv(t_data *st)
{
	int		i;
	int		ret;

	i = 1;
	ret = 1;
	if (!st->cmd[1])
		return (ft_putenv(st));
	else
	{
		while (st->cmd[i])
		{
			ret = set_var_env(st, st->cmd[i]);
			i++;
		}
	}
	return (ret);
}
