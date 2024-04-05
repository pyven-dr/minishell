/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 05:07:36 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/05 05:07:36 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_fds(t_utils *utils)
{
	size_t	i;
	int		fd;

	i = 0;
	while (i < utils->fds_vector->size)
	{
		fd = *(int*)get_elem_vector(utils->fds_vector, i);
		close(fd);
		i++;
	}
}
