/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agreau <agreau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 05:35:47 by agreau            #+#    #+#             */
/*   Updated: 2014/03/27 04:44:26 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_STRUCT_H
# define SH_STRUCT_H

typedef struct			s_lex
{
	int					ope;
	char				*val;
	struct s_lex		*next;
	struct s_lex		*prev;
}						t_lex;

typedef struct			s_parse
{
	int					id;
	int					range;
	char				*val;
	struct s_parse		*father;
	struct s_parse		*right;
	struct s_parse		*left;
}						t_parse;

typedef struct			s_data
{
	char				**envtab;
	char				**split_path;
	char				**cmd;
	char				*line;
	t_lex				*lex;
	t_parse				*parse;
	char				*bina;
	int					fd_history;
	int					history_last;
	int					first_history;
	int					reset;
	int					incmd;
	int					plen;
	int					linelen;
}						t_data;

#endif
