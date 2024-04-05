/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_double_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:54:50 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/25 23:54:50 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_double_out(t_tree *node, t_utils *utils)
{
	int	oldfd;
	int	newfd;
	int	exec_val;

	newfd = open(node->name, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (newfd == -1)
	{
		perror("Redirect in error");
		return (-1);
	}
	oldfd = dup(STDOUT_FILENO);
	if (oldfd == -1)
	{
		perror("Dup error");
		close(newfd);
		return (-1);
	}
	if (dup_fd(newfd, STDOUT_FILENO) == -1)
		return (-1);
	exec_val = exec(node->left, utils);
	if (dup_fd(oldfd, STDOUT_FILENO) == -1)
		return (-1);
	return (exec_val);
}
