/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 10:53:09 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:23 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int				len_str(long unsigned int n)
{
	int					i;

	i = 1;
	while (n / 16 != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int				hexprint(long unsigned int n, char c)
{
	long unsigned int	ret;

	ret = n % 16;
	if (ret <= 9)
		return (ret + '0');
	else
	{
		if (c == 'x')
			return (ret + 87);
		else
			return (ret + 55);
	}
}

char					*ft_xitoa(long unsigned int n, char c)
{
	char				*str;
	size_t				i;

	i = len_str(n);
	str = ft_strnew(i);
	if (str)
	{
		if (!n)
			str[0] = '0';
		while (n)
		{
			str[--i] = hexprint(n, c);
			n = n / 16;
		}
	}
	return (str);
}
