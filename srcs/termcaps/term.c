/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 20:55:36 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <termios.h>
#include <term.h>

int			init_term(t_data *st)
{
	char				*term_name;
	struct termios		term;

	term_name = ft_getenv(st->envtab, "TERM");
	if (term_name == NULL)
		term_name = "xterm-256color";
	tgetent(NULL, term_name);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_oflag &= ~(OPOST);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	return (2);
}

int			ft_outc(int c)
{
	write(isatty(1), &c, 1);
	return (0);
}

int			ft_putstr_term(char *str, t_data *st)
{
	int		char_to_print;
	char	*term_name;

	term_name = ft_getenv(st->envtab, "TERM");
	if (term_name == NULL)
		term_name = "xterm-256color";
	tgetent(NULL, term_name);
	ft_prompt(st);
	char_to_print = st->plen + ft_strlen(str);
	st->linelen = (char_to_print / (tgetnum("co") + 1)) + 1;
	ft_putstr_fd(str, isatty(1));
	return (char_to_print);
}

int			ft_putstr_complete(char *str, t_data *st)
{
	int		char_to_print;
	char	*term_name;

	term_name = ft_getenv(st->envtab, "TERM");
	if (term_name == NULL)
		term_name = "xterm-256color";
	tgetent(NULL, term_name);
	ft_putstr_fd("> ", isatty(1));
	char_to_print = 2 + ft_strlen(str);
	st->linelen = (char_to_print / (tgetnum("co") + 1)) + 1;
	ft_putstr_fd(str, isatty(1));
	return (char_to_print);
}

int			reset_term(t_data *st)
{
	char				*term_name;
	struct termios		term;

	term_name = ft_getenv(st->envtab, "TERM");
	if (term_name == NULL)
		term_name = "xterm-256color";
	tgetent(NULL, term_name);
	tcgetattr(0, &term);
	term.c_lflag |= (ICANON | ECHO);
	term.c_oflag |= (OPOST);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	return (0);
}
