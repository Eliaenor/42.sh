/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 09:43:57 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:23 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftsh.h"

void	base_env(char **environ, t_data *st)
{
	char		*lvl;

	create_envtab(st, environ);
	lvl = NULL;
	lvl = ft_getenv(st->envtab, "SHLVL");
	if (lvl)
		set_var_env(st, ft_strjoin("SHLVL=", ft_itoa(ft_atoi(lvl) + 1)));
	if (!ft_getenv(st->envtab, "HOME"))
		set_var_env(st, "HOME=/");
	if (!ft_getenv(st->envtab, "PWD"))
		set_var_env(st, ft_strjoin("PWD=", getcwd(NULL, 1024)));
	if (!ft_getenv(st->envtab, "OLDPWD"))
		set_var_env(st, ft_strjoin("OLDPWD=", getcwd(NULL, 1024)));
	if (!ft_getenv(st->envtab, "USER"))
		set_var_env(st, "USER=USER");
	if (!ft_getenv(st->envtab, "PATH"))
		set_var_env(st, "PATH=/user/local/bin:/bin");
}

void	create_envtab(t_data *st, char **environ)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	st->envtab = NULL;
	while (environ[i])
		i++;
	if ((st->envtab = (char **)malloc(sizeof(char *) * (i + 1))))
	{
		while (j < i)
		{
			st->envtab[j] = ft_strdup(environ[j]);
			j++;
		}
		st->envtab[j] = NULL;
	}
}
