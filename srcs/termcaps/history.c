/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 09:27:19 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <fcntl.h>

int		init_history(t_data *st)
{
	st->history_last = 0;
	st->first_history = 0;
	st->fd_history = open(".42history", O_RDWR | O_CREAT,
							S_IRWXU | S_IRWXO | S_IRWXG);
	lseek(st->fd_history, -1, SEEK_END);
	return (0);
}

char	*get_prev_line(int fd, t_data *st)
{
	char	*line;
	char	*buff;

	if (lseek(fd, -1, SEEK_CUR) == 0)
		st->first_history = 1;
	line = (char *)malloc(1);
	buff = (char *)malloc(2);
	line[0] = '\0';
	line = ft_miniread(line, buff, st, fd);
	return (line);
}

char	*get_next_line_m(int fd)
{
	char	*line;
	char	buff[2];

	line = (char *)malloc(1);
	line[0] = '\0';
	buff[1] = '\0';
	if (read(fd, buff, 1) && buff[0] != '\n')
		line = add_to_tab(line, buff[0], ft_strlen(line));
	while (read(fd, buff, 1) && buff[0] != '\n')
		line = add_to_tab(line, buff[0], ft_strlen(line));
	lseek(fd, -1, SEEK_CUR);
	return (line);
}

char	*ft_miniread(char *line, char *buff, t_data *st, int fd)
{
	while (read(fd, buff, 1) && buff[0] != '\n')
	{
		buff[1] = '\0';
		line = add_to_tab(line, buff[0], 0);
		if (!lseek(fd, -2, SEEK_CUR))
		{
			if (st->first_history == 0)
			{
				read(fd, buff, 1);
				line = add_to_tab(line, buff[0], 0);
			}
			else
				return (NULL);
			return (line);
		}
		ft_bzero(buff, 2);
	}
	lseek(fd, -1, SEEK_CUR);
	return (line);
}
