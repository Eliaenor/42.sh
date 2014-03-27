/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 09:48:57 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <term.h>
#include <dirent.h>

int		tab_key(t_data *st, char **buff, int j)
{
	char	*word;
	char	*comp;
	int		ret;

	comp = NULL;
	word = get_curent_word(*buff, j - 1);
	if (word == NULL)
	{
		if ((word = bell_for_tab(*buff, j)) == NULL)
			return (j);
	}
	ret = ft_infolder(st, word, &comp);
	if (ret == 2)
	{
		delete_cmd(st, j);
		j = add_tab_to_buff(buff, j, comp, word);
		ft_putstr_term(*buff, st);
	}
	else if (ret == 3 || ret == 1)
		ft_putstr_term(*buff, st);
	else if (ret == 0)
		tputs(tgetstr("bl", NULL), 0, ft_outc);
	return (j);
}

int		ft_infolder(t_data *st, char *word, char **comp)
{
	char			*path;
	int				i;
	int				display;

	path = NULL;
	display = 1;
	set_path_and_word(&word, &path);
	i = get_nbr_match(path, word, comp);
	if (i >= 100)
		display = ft_y_or_n(st, i, path, word);
	else if (i == 1)
		display = 2;
	else if (i == 0)
		display = 0;
	else
		return (exec_ls(st, path, word));
	return (display);
}

int		get_nbr_match(char *path, char *word, char **comp)
{
	int				i;
	DIR				*dp;
	struct dirent	*dirp;

	i = 0;
	if ((dp = opendir(path)) == NULL)
		return (0);
	while ((dirp = readdir(dp)))
	{
		if (word == NULL)
			i++;
		else if (ft_strncmp(word, dirp->d_name, ft_strlen(word)) == 0)
		{
			*comp = ft_strdup(dirp->d_name);
			i++;
		}
	}
	closedir(dp);
	return (i);
}

int		set_path_and_word(char **word, char **path)
{
	char			*pathtmp;

	if (ft_strchr(*word, '/'))
	{
		pathtmp = ft_strcut_end(*word, '/');
		*path = (ft_strjoin(getcwd(NULL, 1024), "/"));
		*path = (ft_strjoin(*path, pathtmp));
		*path = (ft_strjoin(*path, "/"));
		free(*word);
		*word = ft_get_end(*word, '/');
	}
	else
		*path = (ft_strjoin(getcwd(NULL, 1024), "/"));
	return (0);
}

char	*get_curent_word(char *buff, int i)
{
	int		tmp;
	char	*word;
	int		j;

	j = 0;
	if (buff[0] == '\0')
		return (NULL);
	while (i != 0 && (buff[i] == ' ' || buff[i] == '\t'))
		i--;
	tmp = i;
	while (i != 0 && buff[i] != ' ')
		i--;
	if (i <= 0)
		return (NULL);
	word = (char *)malloc(sizeof(char) * ((tmp - i)));
	if (i != 0)
		i++;
	while (i <= tmp)
		word[j++] = buff[i++];
	word[j] = '\0';
	return (word);
}
