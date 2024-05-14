/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_fds_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:01:25 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/14 00:01:25 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	remove_fds_vector(int oldfd, t_vector *fds_vector)
{
	int	i;
	int	*elem;

	i = 0;
	elem = get_elem_vector(fds_vector, 0);
	while (elem != NULL)
	{
		if (*elem == oldfd)
			if (del_elem_vector(fds_vector, i, NULL) == 1)
				return (1);
		i++;
		elem = get_elem_vector(fds_vector, 0);
	}
	return (0);
}
