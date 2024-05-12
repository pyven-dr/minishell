/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:58:50 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/24 18:58:50 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_simple_in(t_tree *node, t_utils *utils)
{
	int	oldfd;
	int	newfd;
	int	exec_val;

	exec_val = 0;
	if (expand_redirect(node, utils->env_vector) == 1)
		return (-1);
	newfd = open(node->name, O_RDONLY);
	if (newfd == -1)
	{
		perror("minishell: Redirect in error");
		return (-1);
	}
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
	return (exec_val);
}
