/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabkey_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 08:58:00 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <dirent.h>
#include <sys/stat.h>
#include <term.h>

int		exec_ls(t_data *st, char *path, char *word)
{
	pid_t	father;
	char	*oldir;
	char	**args;

	ft_putstr("\n");
	tputs(tgetstr("cr", NULL), 0, ft_outc);
	oldir = ft_strjoin(getcwd(NULL, 1024), "/");
	chdir(path);
	args = get_tbl_ls(ft_strsplit(get_full_arg_ls(word), ' '));
	reset_term(st);
	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
		execve("/bin/ls", args, st->envtab);
	chdir(oldir);
	init_term(st);
	return (1);
}

char	*get_full_arg_ls(char *word)
{
	DIR				*dp;
	struct dirent	*dirp;
	char			*args;

	args = NULL;
	dp = opendir(ft_strjoin(getcwd(NULL, 1024), "/"));
	while ((dirp = readdir(dp)))
	{
		if (dirp->d_name[0] != '.')
		{
			if (ft_strncmp(word, dirp->d_name, ft_strlen(word)) == 0)
			{
				if (args == NULL)
					args = ft_strdup(dirp->d_name);
				else
				{
					args = ft_strjoin(args, " ");
					args = ft_strjoin(args, dirp->d_name);
				}
			}
		}
	}
	closedir(dp);
	return (args);
}

int		add_tab_to_buff(char **buff, int j, char *comp, char *word)
{
	struct stat		stats;
	char			*total_path;
	char			*path;

	*buff = add_str_to_tab(*buff, &(comp[ft_strlen(word)]), j);
	path = ft_get_end(*buff, ' ');
	total_path = ft_strjoin(getcwd(NULL, 1024), "/");
	total_path = ft_strjoin(total_path, path);
	stat(total_path, &stats);
	if ((stats.st_mode & S_IFDIR) != 0)
	{
		j++;
		*buff = add_to_tab(*buff, '/', ft_strlen(*buff));
	}
	j = j + (ft_strlen(comp) - ft_strlen(word));
	return (j);
}

char	**get_tbl_ls(char **fullarg)
{
	char	**args;
	int		i;
	int		j;

	i = 2;
	j = 0;
	args = (char **)malloc(sizeof(char *) * (ft_tablen(fullarg) + 3));
	args[0] = "ls";
	args[1] = "-Cd";
	while (fullarg[j])
		args[i++] = fullarg[j++];
	args[i] = NULL;
	return (args);
}

int		ft_y_or_n(t_data *st, int i, char *path, char *word)
{
	char	stdin[3];

	tputs(tgetstr("cr", NULL), 0, ft_outc);
	ft_putstr("\nDisplay all ");
	ft_putnbr(i);
	ft_putstr(" possibilities? (y or n)");
	ft_bzero(stdin, 3);
	while (read(1, &stdin, 3))
	{
		if (stdin[0] == 32 || stdin[0] == 121)
			return (exec_ls(st, path, word));
		if (stdin[0] == 110)
		{
			tputs(tgetstr("cr", NULL), 0, ft_outc);
			tputs(tgetstr("do", NULL), 0, ft_outc);
			return (3);
		}
		else
			ft_bzero(stdin, 3);
	}
	return (0);
}
