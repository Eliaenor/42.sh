/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:23:02 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:23 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_white(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (is_white(s[i]))
		s++;
	while (s[i])
		i++;
	while (i-- > 0 && is_white(s[i]))
		;
	ret = ft_strsub(s, 0, i + 1);
	if (ret)
	{
		return (ret);
	}
	return (NULL);
}
