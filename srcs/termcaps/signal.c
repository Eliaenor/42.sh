/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 21:09:39 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 01:36:24 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"
#include <signal.h>
#include <term.h>

t_data		*g_st_signal;

int			ft_init_global(t_data *st)
{
	g_st_signal = st;
	signal(2, sig_ctrl_c);
	signal(3, sig_ctrl_c);
	return (0);
}

void		sig_ctrl_c(int n)
{
	(void)n;
	signal(2, sig_ctrl_c);
	signal(3, sig_ctrl_c);
	ft_putchar('\n');
	tputs(tgetstr("cr", NULL), 0, ft_outc);
	if (g_st_signal->incmd == 0)
		ft_prompt(g_st_signal);
	g_st_signal->reset = 1;
}

void		ft_sig_off(void)
{
	signal(2, SIG_DFL);
	signal(3, SIG_DFL);
}
