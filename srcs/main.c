/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agreau <agreau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 17:33:16 by fdabiel           #+#    #+#             */
/*   Updated: 2014/03/27 01:38:58 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftsh.h"
#include <term.h>

int		main(void)
{
	t_data			st;
	extern char		**environ;

	base_env(environ, &st);
	init_history(&st);
	if (ft_getenv(st.envtab, "PATH") != NULL)
		st.split_path = ft_strsplit(ft_getenv(st.envtab, "PATH"), ':');
	while (42)
	{
		if (ft_get_entry(&st) <= 0)
			exit(0);
		reset_term(&st);
		tputs(tgetstr("ei", NULL), 0, ft_outc);
		if (st.line != NULL && *(ft_strtrim(st.line)))
		{
			sh_lexing(&st);
			sh_parsing(&st);
			sh_cmd_exec(&st, st.parse);
		}
		free(st.line);
	}
	return (0);
}
