/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:29:42 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:23 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		length_s1;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	length_s1 = ft_strlen(s1);
	while (*s2 && i < n)
	{
		s1[length_s1 + i] = s2[i];
		i = i + 1;
	}
	s1[length_s1 + i] = '\0';
	return (s1);
}
