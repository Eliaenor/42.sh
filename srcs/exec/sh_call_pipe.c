/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_call_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srieu-si <srieu-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:39:40 by srieu-si          #+#    #+#             */
/*   Updated: 2014/03/27 05:39:43 by srieu-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

int		sh_pipe(t_data *st, t_parse *node)
{
	pid_t	father;
	int		fd[2];
	int		ret;

	pipe(fd);
	father = fork();
	if (father)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		ret = sh_cmd_exec(st, node->right);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		sh_cmd_exec(st, node->left);
		close(fd[1]);
		exit(0);
	}
	return (ret);
}
