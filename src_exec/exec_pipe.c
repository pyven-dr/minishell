/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:36:22 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/23 04:36:22 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	*create_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) < 0)
		return (NULL);
	return (pipe_fd);
}

static int	dup_fd(int fd, int pipe_fd[2])
{
	int	val;

	val = -1;
	if (fd == STDOUT_FILENO)
		val = dup2(pipe_fd[1], STDOUT_FILENO);
	else if (fd == STDIN_FILENO)
		val = dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (val < 0)
	{
		perror("Dup2 Error");
		return (1);
	}
	return (0);
}

static int	exec_node_pipe(int pipe_fd[2], t_tree *node, int fd)
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
		if (dup_fd(fd, pipe_fd) != 0)
			exit(1);
		exec_id = exec(node);
		status = check_id(exec_id);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		exit(status);
	}
	return (id);
}

int	exec_pipe(t_tree *node)
{
	pid_t	id_left;
	pid_t	id_right;
	int		pipe_fd[2];

	if (create_pipe(pipe_fd) == NULL)
		return (-1);
	id_left = exec_node_pipe(pipe_fd, node->left, STDOUT_FILENO);
	id_right = exec_node_pipe(pipe_fd, node->right, STDIN_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(id_left, NULL, 0);
	return (check_id(id_right));
}
