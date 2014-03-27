/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 10:53:09 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:19 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	len_str(unsigned int n)
{
	int		i;

	i = 1;
	while (n / 8 != 0)
	{
		n = n / 8;
		i++;
	}
	return (i);
}

char		*ft_oitoa(unsigned int n)
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
			str[--i] = (n % 8) + '0';
			n = n / 8;
		}
	}
	return (str);
}
