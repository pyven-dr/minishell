/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:43:32 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/25 23:43:32 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_simple_out(t_tree *node, t_utils *utils)
{
	int	oldfd;
	int	newfd;
	int	exec_val;

	exec_val = 0;
	newfd = open(node->name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (newfd == -1)
	{
		perror("Redirect in error");
		return (-1);
	}
	oldfd = dup_oldfd(utils, STDOUT_FILENO);
	if (oldfd == -1)
	{
		close(newfd);
		return (-1);
	}
	if (dup_fd(newfd, STDOUT_FILENO) == -1)
		return (-1);
	if (node->left != NULL)
		exec_val = exec(node->left, utils);
	if (dup_fd(oldfd, STDOUT_FILENO) == -1)
		return (-1);
	return (exec_val);
}
