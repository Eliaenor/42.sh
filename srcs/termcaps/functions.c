/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 21:17:18 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

char	**ft_tabdup(char **tbl1)
{
	char	**tbl2;
	int		i;

	i = 0;
	while (tbl1[i])
		i++;
	tbl2 = (char **)malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (tbl1[i])
	{
		tbl2[i] = ft_strdup(tbl1[i]);
		i++;
	}
	tbl2[i] = NULL;
	return (tbl2);
}

char	*add_to_tab(char *tbl, char c, int pos)
{
	int		i;
	char	tmp;
	char	tmp2;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(tbl) + 2));
	while (i < pos)
	{
		dest[i] = tbl[i];
		i++;
	}
	tmp = tbl[i];
	dest[i++] = c;
	while (tbl[i] != '\0')
	{
		tmp2 = tbl[i];
		dest[i] = tmp;
		tmp = tmp2;
		i++;
	}
	dest[i] = tmp;
	dest[i + 1] = '\0';
	return (dest);
}

char	*add_str_to_tab(char *tbl, char *str, int pos)
{
	int		i;
	int		j;
	int		tmp;
	char	*dest;

	i = 0;
	j = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(tbl) + ft_strlen(str) + 1));
	while (i < pos)
	{
		dest[i] = tbl[i];
		i++;
	}
	tmp = i;
	while (str[j] != '\0')
		dest[i++] = str[j++];
	j = tmp;
	while (tbl[j] != '\0')
		dest[i++] = tbl[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcut_end(char const *s, char c)
{
	int		i;
	int		size;
	int		len;
	int		tmp;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	i = len - 1;
	while (s[i] != c)
		i--;
	tmp = i;
	size = len - (len - i);
	str = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < tmp)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_end(char const *s, char c)
{
	int		i;
	int		j;
	int		size;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	size = 0;
	len = ft_strlen(s);
	j = len - 1;
	while (s[j] != c)
		j--;
	j++;
	size = len - i;
	str = (char *)malloc(sizeof(char) * (size + 1));
	while (s[j] != '\0')
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
