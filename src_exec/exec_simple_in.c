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

int dup_fd(int fd1, int fd2)
{
	int	dup_val;

	dup_val = dup2(fd1, fd2);
	close(fd1);
	if (dup_val < 0)
	{
		perror("Dup2 error");
		return (-1);
	}
	return (0);
}

int	exec_simple_in(t_tree *node)
{
	int	oldfd;
	int	newfd;
	int exec_val;

	newfd = open(node->name, O_RDONLY);
	if (newfd == -1)
	{
		perror("Redirect in error");
		return (-1);
	}
	oldfd = dup(STDIN_FILENO);
	if (oldfd < 0)
	{
		perror("Dup error");
		return (-1);
	}
	if (dup_fd(newfd, STDIN_FILENO) == -1)
		return (-1);
	exec_val = exec(node->left);
	if (dup_fd(oldfd, STDIN_FILENO) == -1)
		return (-1);
	char *args[] = {"echo","10",NULL};
	printf("%d\n",STDIN_FILENO);
	execvp("echo", args);
	return (exec_val);
}