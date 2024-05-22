/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_double_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 02:44:53 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/01 02:44:53 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_redir.h"

int	exec_double_in(t_tree *node, t_utils *utils)
{
	int	oldfd;
	int	newfd;
	int	exec_val;

	exec_val = 0;
	newfd = open(node->name, O_RDONLY);
	if (newfd == -1)
		return (perror("minishell: Redirect in error"), -1);
	oldfd = dup_oldfd(utils, STDIN_FILENO);
	if (oldfd == -1)
	{
		close(newfd);
		return (-1);
	}
	if (dup_fd(newfd, STDIN_FILENO) == -1)
		return (-1);
	if (node->left != NULL)
		exec_val = exec(node->left, utils);
	if (dup_fd(oldfd, STDIN_FILENO) == -1)
		return (-1);
	if (remove_fds_vector(oldfd, utils->fds_vector) == 1)
		return (1);
	if (unlink(node->name) == -1)
		return (perror("minishell: unlink"), -1);
	return (exec_val);
}
