/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_call_opshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 08:06:29 by vcourtin          #+#    #+#             */
/*   Updated: 2014/03/27 08:06:34 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

int		sh_sem(t_data *st, t_parse *node)
{
	sh_cmd_exec(st, node->left);
	sh_cmd_exec(st, node->right);
	return (0);
}

int		sh_and(t_data *st, t_parse *node)
{
	if (!(sh_cmd_exec(st, node->left)))
		sh_cmd_exec(st, node->right);
	return (0);
}

int		sh_or(t_data *st, t_parse *node)
{
	if (sh_cmd_exec(st, node->left))
		sh_cmd_exec(st, node->right);
	return (0);
}
