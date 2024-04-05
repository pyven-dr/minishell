/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_node_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:33:51 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/05 04:33:51 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_node_pipe(int pipe_fd[2], t_tree *node, int fd, t_utils *utils)
{
	pid_t	id;
	int		exec_id;
	int		status;

	status = 0;
	id = fork();
	if (id < 0)
	{
		perror("fork error");
		return (-1);
	}
	if (id == 0)
	{
		if (redirect_fd(fd, pipe_fd) != 0)
			exit(1);
		exec_id = exec(node, utils);
		status = check_id(exec_id);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		exit(status);
	}
	return (id);
}
