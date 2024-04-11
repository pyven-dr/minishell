/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_elem_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:37:03 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/09 16:37:03 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	del_elem_vector(t_vector *vector, size_t i, void (*ft_free) (void *elem))
{
	if (i > vector->size)
		return (1);
	ft_bzero(vector->elements + i * vector->elem_size, vector->elem_size);
	while (i < vector->size)
	{
		ft_memcpy(vector->elements + i * vector->elem_size, \
				vector->elements + (i + 1) * vector->elem_size, \
				vector->elem_size);
		i++;
	}
	if (get_elem_vector(vector, i) != NULL)
		if (ft_free != NULL)
			ft_free(vector->elements + i * vector->elem_size);
	vector->size--;
	return (0);
}
