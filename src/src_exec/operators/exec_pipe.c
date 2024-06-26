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
#include "exec_pipe.h"
#include <sys/wait.h>

int	exec_pipe(t_tree *node, t_utils *utils)
{
	pid_t	id_left;
	pid_t	id_right;
	int		pipe_fd[2];

	if (create_pipe(pipe_fd) == NULL)
		return (-1);
	id_left = exec_node_pipe(pipe_fd, node->left, STDOUT_FILENO, utils);
	id_right = exec_node_pipe(pipe_fd, node->right, STDIN_FILENO, utils);
	if (close(pipe_fd[0]) == -1)
	{
		close(pipe_fd[1]);
		return (-1);
	}
	if (close(pipe_fd[1]) == -1)
		return (-1);
	waitpid(id_left, NULL, 0);
	return (check_id_pipe(id_right, utils));
}
