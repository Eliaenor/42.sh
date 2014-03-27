/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:51:36 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:21 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	lens1;
	size_t	lens2;

	lens1 = 0;
	lens2 = 0;
	while (s1[lens1])
		lens1++;
	while (s2[lens2])
		s1[lens1++] = s2[lens2++];
	s1[lens1] = '\0';
	return (s1);
}
