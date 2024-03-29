/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:32:54 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:22 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_striter(char *s, void (*f)(char *))
{
	size_t	i;

	i = 0;
	while (s[i])
		(*f)(&s[i++]);
}
