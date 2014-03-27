/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 01:41:01 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:41:05 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <dirent.h>
#include <sys/stat.h>

static void		ft_change_part2(char **args, char *env_pwd, t_data *st)
{
	char	*path;

	if (args[1] && ft_strcmp(args[1], "-") == 0)
	{
		path = ft_strjoin(env_pwd, ft_getenv(st->envtab, "OLDPWD"));
		ft_putendl(ft_getenv(st->envtab, "OLDPWD"));
		set_var_env(st, ft_strjoin("OLDPWD=", getcwd(NULL, 1024)));
		chdir(path);
	}
	else if (args[1] && args[1][0] == '~')
	{
		path = ft_strjoin(ft_getenv(st->envtab, "HOME"), "/");
		path = ft_strjoin(path, &(args[1][1]));
		chdir(path);
	}
}

static void		check_right(char **path, char **args, t_data *st)
{
	struct stat		stats;

	if (stat(*path, &stats) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(args[1]);
		*path = ft_getenv(st->envtab, "PWD");
	}
	else if ((stats.st_mode & S_IRUSR) == 0)
	{
		ft_putstr("cd: permission denied: ");
		ft_putendl(args[1]);
		*path = ft_getenv(st->envtab, "PWD");
	}
	else if ((stats.st_mode & S_IFDIR) == 0)
	{
		ft_putstr("cd: not a directory: ");
		ft_putendl(args[1]);
		*path = ft_getenv(st->envtab, "PWD");
	}
}

int				sh_cd(t_data *st)
{
	char	*env_pwd;
	char	*path;

	env_pwd = ft_strjoin(ft_getenv(st->envtab, "PWD"), "/");
	if (st->cmd[1] && (ft_strcmp(st->cmd[1], "-") == 0 || st->cmd[1][0] == '~'))
		ft_change_part2(st->cmd, env_pwd, st);
	else if (st->cmd[1])
	{
		path = ft_strjoin(env_pwd, st->cmd[1]);
		check_right(&path, st->cmd, st);
		set_var_env(st, ft_strjoin("OLDPWD=", getcwd(NULL, 1024)));
		path = (st->cmd[1][0] == '/' ? st->cmd[1] : path);
		chdir(path);
	}
	else
	{
		path = ft_getenv(st->envtab, "HOME");
		set_var_env(st, ft_strjoin("OLDPWD=", getcwd(NULL, 1024)));
		chdir(path);
	}
	free(env_pwd);
	set_var_env(st, ft_strjoin("PWD=", getcwd(NULL, 1024)));
	return (0);
}
