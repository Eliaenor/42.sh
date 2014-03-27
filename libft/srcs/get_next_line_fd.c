/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agreau <agreau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 05:35:48 by agreau            #+#    #+#             */
/*   Updated: 2014/03/27 01:36:23 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		read_get_next_line(int fd, int *i, int *nbread, char *buff)
{
	if (*i == *nbread)
	{
		*i = 0;
		if (!(*nbread = read(fd, buff, BUFF_SIZE)))
			return (1);
	}
	return (0);
}

int		eol_get_next_line(int fd, int *i, int *nbread, char *buff)
{
	while (buff[*i] && buff[*i] != '\n')
	{
		(*i)++;
		if (read_get_next_line(fd, i, nbread, buff))
			return (1);
	}
	return (0);
}

char	*get_next_line_fd(int fd)
{
	static char		buff[BUFF_SIZE];
	static int		i = 0;
	static int		nbread = 0;
	int				n;
	char			*str;

	str = NULL;
	n = 0;
	if (read_get_next_line(fd, &i, &nbread, buff))
		return (0);
	str = malloc(sizeof(char) * BUFF_SIZE);
	while (buff[i] && buff[i] != '\n' && n < BUFF_SIZE)
	{
		str[n++] = buff[i++];
		if (read_get_next_line(fd, &i, &nbread, buff))
			return (str);
	}
	if (n == BUFF_SIZE)
		if (eol_get_next_line(fd, &i, &nbread, buff))
			return (str);
	i++;
	return (str);
}
