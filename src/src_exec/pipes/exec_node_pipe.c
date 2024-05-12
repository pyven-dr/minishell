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

static int close_all(t_utils *utils)
{
	int	ret_val;

	ret_val = 0;
	if (close(STDIN_FILENO) == -1)
		ret_val = 1;
	if (close(STDOUT_FILENO) == -1)
		ret_val = 1;
	if (close_fds(utils) == 1)
		ret_val = 1;
	del_vector(utils->fds_vector, NULL);
	return (ret_val);
}

int	exec_node_pipe(int pipe_fd[2], t_tree *node, int fd, t_utils *utils)
{
	pid_t	id;
	int		exec_id;
	int		status;

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
		if (close_all(utils) == 1)
			exit(1);
		exit(status);
	}
	return (id);
}
