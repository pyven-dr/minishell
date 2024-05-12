/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:40:32 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/25 23:40:32 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	dup_fd(int fd1, int fd2)
{
	int	dup_val;

	dup_val = dup2(fd1, fd2);
	if (close(fd1) == -1)
		return (-1);
	if (dup_val < 0)
	{
		perror("minishell: Dup2 error");
		return (-1);
	}
	return (0);
}
