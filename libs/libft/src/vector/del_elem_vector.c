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

int	del_elem_vector(t_vector *vector, size_t index, void(*ft_free) (void *elem))
{
	if (index > vector->size)
		return (1);
	ft_bzero(vector->elements + index * vector->elem_size, vector->elem_size);
	while (index < vector->size)
	{
		ft_memcpy(vector->elements + index * vector->elem_size, \
				vector->elements + (index + 1) * vector->elem_size, \
				vector->elem_size);
		index++;
	}
	if (get_elem_vector(vector, index) != NULL)
		if (ft_free != NULL)
			ft_free(vector->elements + index * vector->elem_size);
	vector->size--;
	return (0);
}
