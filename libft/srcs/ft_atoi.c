/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdabiel <fdabiel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:15:56 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:36:19 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_search_white(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' ||
				c == '\f' || c == '\v')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		mul;

	i = 0;
	n = 0;
	mul = -1;
	while (ft_search_white(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			mul = -mul;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 - (str[i++] - '0');
	return (n * mul);
}
