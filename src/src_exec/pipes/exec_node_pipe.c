/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_node_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:33:51 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/08 15:33:31 by sabitbol         ###   ########.fr       */
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
		perror("minishell: fork error");
		return (-1);
	}
	if (id == 0)
	{
		if (redirect_fd(fd, pipe_fd) != 0)
			exit(1);
		exec_id = exec(node, utils);
		status = check_id(exec_id, utils);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close_fds(utils);
		del_vector(utils->fds_vector, NULL);
		exit(status);
	}
	return (id);
}
