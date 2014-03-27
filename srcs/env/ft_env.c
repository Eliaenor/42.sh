/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 05:42:32 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

static int		add_env_mini(char *line, char **env)
{
	int		i;
	char	**newenv;

	i = 0;
	if (!(newenv = (char**)malloc(sizeof(char*) * (ft_tablen(env) + 1))))
		return (0);
	while (env[i])
	{
		newenv[i] = ft_strdup(env[i]);
		i++;
	}
	newenv[i++] = ft_strdup(line);
	newenv[i] = NULL;
	env = newenv;
	return (1);
}

static char		**check_env_mini(char *line, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], line, ft_strchr(line, '=') - line) == 0)
			return (env + i);
		i++;
	}
	return (NULL);
}

static int		set_var(char **env, char *line)
{
	char	**envtmp;

	if (!ft_strchr(line, '='))
		return (0);
	if (!(envtmp = check_env_mini(line, env)))
	{
		if (!add_env_mini(line, env))
			return (0);
	}
	else
		*check_env_mini(line, env) = ft_strdup(line);
	return (1);
}

static int		sh_env_mini(char **env, char **cmd, int i)
{
	while (cmd[i] && ft_strchr(cmd[i], '='))
	{
		set_var(env, cmd[i]);
		i++;
	}
	/*if (ft_exec() == 0)
	{
		free(env);
		return (1);
	}*/
	free(env);
	return (0);
}

int				sh_env(t_data *st)
{
	char	**newenv;
	int		i;

	i = 1;
	newenv = NULL;
	if (!st->cmd[i])
		return (ft_putenv(st));
	else if (ft_strcmp(st->cmd[i], "-i") == 0 && !st->cmd[i + 1])
		return (1);
	else if (ft_strcmp(st->cmd[i], "-i") == 0)
	{
		newenv = (char **)malloc(sizeof(char *));
		newenv[0] = NULL;
		i++;
		sh_env_mini(newenv, st->cmd, i);
	}
	else
	{
		newenv = ft_env_dup(st->envtab);
		sh_env_mini(newenv, st->cmd, i);
	}
	return (0);
}
