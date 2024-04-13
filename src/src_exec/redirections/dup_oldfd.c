/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_oldfd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:09:19 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/05 23:09:19 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	dup_oldfd(t_utils *utils, int fd)
{
	int	oldfd;

	oldfd = dup(fd);
	if (oldfd == -1)
	{
		perror("Dup error");
		return (-1);
	}
	if (add_vector(utils->fds_vector, &oldfd, NULL) == -1)
		return (-1);
	return (oldfd);
}
