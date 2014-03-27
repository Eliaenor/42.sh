/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 10:19:58 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

char	*ft_getenv(char **envtab, char *env)
{
	int			i;
	char		*ret;

	i = 0;
	while (envtab[i])
	{
		if (ft_strnequ(envtab[i], env, ft_strlen(env)))
		{
			if (*(envtab[i] + ft_strlen(env)) == '=')
			{
				ret = ft_strdup(envtab[i] + ft_strlen(env) + 1);
				return (ret);
			}
		}
		i++;
	}
	return (NULL);
}

char	**ft_env_dup(char **environ)
{
	int		i;
	int		j;
	char	**newenv;

	i = 0;
	j = 0;
	newenv = NULL;
	while (environ[i])
		i++;
	if ((newenv = (char **)malloc(sizeof(char *) * (i + 1))))
	{
		while (j < i)
		{
			newenv[j] = ft_strdup(environ[j]);
			j++;
		}
		newenv[j] = NULL;
	}
	return (newenv);
}

int		ft_putenv(t_data *st)
{
	int			i;

	i = 0;
	while (st->envtab[i])
	{
		ft_putendl(st->envtab[i]);
		i++;
	}
	return (0);
}

int		ft_tablen(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
