/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agreau <agreau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 05:07:13 by agreau            #+#    #+#             */
/*   Updated: 2014/03/27 08:19:17 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

/*
 *@fn				is_valid_operator(char *str)
 *@brief			detect if a string is a valid operator or not
 *@param[out] 		str 	string for test
 *@param[in] 		ope 	array of valid operator in range
 *@param[in,out] 	valid 	binary return
 *@param[in] 	 	i 		counter
 *@return 			valid
 */
int		is_valid_operator(char *str)
{
	char	*ope[8] = {";", "&&", "||", "|", ">>", ">", "<", NULL};
	int		valid;
	int		i;

	valid = -1;
	i = 0;
	while (ope[i] != NULL && valid == -1)
	{
		if (!ft_strcmp(str, ope[i]))
			valid = i;
		i++;
	}
	return (valid);
}
/*
 *@fn				detect_ope(char cara)
 *@brief			detect if a character is a part of a valid operator
 *@param[out] 		cara		character for test
 *@param[in] 	 	i 			counter
 *@param[in] 		cara_ope 	array of valid valid character for operator
 *@return 			return 1 if the caracter is in the array else return -1
 */
int		detect_ope(char cara)
{
	int		i;
	int		ok;
	char	cara_ope[5] = {'&', ';', '|', '<', '>'};

	i = 0;
	ok = 0;
	while (cara_ope[i] && ok == 0)
	{
		if (cara == cara_ope[i])
			ok++;
		i++;
	}
	if (ok == 0)
		return (1);
	else
		return (-1);
}
/*
 *@fn				detect_db_ope(t_data *st, int pos, int lex)
 *@brief			detect if a character is the second part of a valid operator
 *@param[out] 		st			struct of storage for all stuff of shell
 *@param[out] 		pos			position of character in cmd
 *@param[out] 		lex			binary var for add to lexer
 *@param[in]		ST_LINE		call of ((*st).line) entry process
 *@param[in] 	 	i 			counter
 *@param[in] 		len 		length of operator
 *@param[in] 		cara_db_ope array of valid valid character for double ope
 *@return 			add to lexer if lex is at 1
 *@return 			len
 */
/*
fonction a revoir
int detect_db_ope(t_data *st, int pos, int lex)
{
	int i;
	int len;
	char cara_db_operator[4] = {'&' , '|', '>', 0};

	i =0;
	while (cara_db_operator[i] != 0)
	{
		if (ST_LINE[pos] == cara_db_operator[i]
			&& ST_LINE[pos + 1] == cara_db_operator[i])
			len = 2;
		else
			len = 1;
		if(lex == 1)
			add_to_lex(st, ft_strsub(ST_LINE, pos, len));
		i++;
	}
	return(len);
}
*/
