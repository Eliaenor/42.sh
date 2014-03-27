/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 10:53:09 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:23 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	len_str(unsigned int n)
{
	int		i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	i;

	i = len_str(n);
	str = ft_strnew(i);
	if (str)
	{
		if (!n)
			str[0] = '0';
		while (n)
		{
			str[--i] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (str);
}
