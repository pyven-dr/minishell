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

int	exec_double_in(t_tree *node, t_utils *utils)
{
	int	oldfd;
	int	newfd;
	int	exec_val;

	newfd = open(node->name, O_RDONLY);
	if (newfd == -1)
	{
		perror("Redirect in error");
		return (-1);
	}
	oldfd = dup(STDIN_FILENO);
	if (oldfd == -1)
	{
		perror("Dup error");
		close(newfd);
		return (-1);
	}
	if (dup_fd(newfd, STDIN_FILENO) == -1)
		return (-1);
	exec_val = exec(node->left, utils);
	if (dup_fd(oldfd, STDIN_FILENO) == -1)
		return (-1);
	unlink(node->name);
	return (exec_val);
}
