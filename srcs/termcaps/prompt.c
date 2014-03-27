/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 08:56:27 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 08:15:36 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftsh.h"

static char		*get_last(char *path)
{
	int			i;

	i = 0;
	if (path)
	{
		if (path[i] == '/' && !path[i + 1])
			return (path);
		while (path[i])
			i++;
		while (path[i - 1] != '/' && i > 0)
			i--;
		if (path[i - 1] == '/')
			return (path + i);
	}
	return (NULL);
}

void			ft_prompt(t_data *st)
{
	char		*prompt;
	char		*current;

	st->plen = 0;
	if (ft_strequ(ft_getenv(st->envtab, "PWD"), ft_getenv(st->envtab, "HOME"))
		&& ft_getenv(st->envtab, "HOME"))
		current = ft_strdup("~");
	else if (get_last(ft_getenv(st->envtab, "PWD")))
		current = get_last(ft_getenv(st->envtab, "PWD"));
	else
		current = ft_strdup("NoPwd");
	if (ft_getenv(st->envtab, "USER"))
	{
		prompt = ft_getenv(st->envtab, "USER");
		st->plen += ft_strlen(ft_strjoin(prompt, " "));
		ft_printincolor(ft_strjoin(prompt, " "), GREEN);
	}
	else
		ft_putstr(GREEN);
	st->plen++;
	ft_printincolor("(", GREEN);
	st->plen += ft_putstr(current);
	ft_putstr(ft_strjoin(ft_putcolor(")", GREEN), " $ "));
	st->plen += 4;
}
