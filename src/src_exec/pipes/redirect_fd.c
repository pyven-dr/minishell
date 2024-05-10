/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:32:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/05 04:32:26 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	redirect_fd(int fd, int pipe_fd[2])
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
		perror("minishell: Dup2 Error");
		return (1);
	}
	return (0);
}
