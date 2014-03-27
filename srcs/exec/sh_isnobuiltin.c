/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_isnobuiltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srieu-si <srieu-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 17:53:38 by srieu-si          #+#    #+#             */
/*   Updated: 2014/03/24 17:53:40 by srieu-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ftsh.h"

int		sh_isnobuiltin(t_data *st)
{
	pid_t	child_pid;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	child_pid = fork();
	if (child_pid != 0)
		waitpid(child_pid, &ret, 0);
	else
	{
		while (st->split_path[i] != NULL)
		{
			st->bina = ft_multistrjoin(3, st->split_path[i], "/", st->cmd[0]);
			if (ft_strchr(st->cmd[0], '/'))
				st->bina = st->cmd[0];
			if (access(st->bina, X_OK) != -1)
				execve(st->bina, st->cmd, st->envtab);
			i++;
		}
		ft_putendl(ft_strjoin(ERR_COMMAND, st->cmd[0]));
		exit(0);
	}
	return (ret);
}
