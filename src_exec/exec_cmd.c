/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:28:24 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/20 00:28:24 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_fds(t_utils *utils)
{
	size_t	i;
	int		fd;

	i = 0;
	while (i < utils->fds_vector->size)
	{
		fd = *(int*)get_elem_vector(utils->fds_vector, i);
		close(fd);
		i++;
	}
}

int	exec_cmd(char **cmd, t_utils *utils)
{
	pid_t	id;

	id = fork();
	if (id < 0)
	{
		perror("Fork error");
		return (-1);
	}
	if (id == 0)
	{
		close_fds(utils);
		execve(cmd[0], cmd, NULL);
		perror("Execve error");
		free_cmd(cmd);
		free(cmd);
		exit(1);
	}
	free_cmd(cmd);
	free(cmd);
	return (id);
}
