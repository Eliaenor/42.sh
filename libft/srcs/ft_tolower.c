/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:34:42 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:23 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	if ((char)c >= 'A' && (char)c <= 'Z')
	{
		c = ((char)c - 'A' + 'a');
	}
	return (c);
}