/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:57:03 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/12/16 20:57:03 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	add_vector(t_vector *vector, void *elem)
{
	size_t	new_capacity;
	void	*new_elements;
	size_t	i;

	i = 0;
	if (vector->size == vector->capacity)
	{
		new_capacity = vector->capacity * 2;
		new_elements = malloc(new_capacity * vector->elem_size);
		if (!new_elements || !elem)
			return (-1);
		ft_memcpy(new_elements, vector->elements, \
			vector->size * vector->elem_size);
		while (i - 1 < vector->size)
		{
			free(vector->elements + i * vector->elem_size);
			i++;
		}
		free(vector->elements);
		vector->elements = new_elements;
		vector->capacity = new_capacity;
	}
	ft_memcpy(vector->elements + vector->size * vector->elem_size, \
		elem, vector->elem_size);
	return (vector->size++, free(elem), 0);
}
