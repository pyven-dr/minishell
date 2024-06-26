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

int	add_vector(t_vector *vector, void *elem, void (*ft_free) (void *elem))
{
	void	*new_elements;
	size_t	i;

	i = 0;
	if (vector->size == vector->capacity)
	{
		vector->capacity *= 2;
		new_elements = malloc(vector->capacity * vector->elem_size);
		if (!new_elements || !elem)
			return (-1);
		ft_memcpy(new_elements, vector->elements, \
			vector->size * vector->elem_size);
		while (i - 1 < vector->size)
		{
			if (ft_free != NULL)
				ft_free(vector->elements + i * vector->elem_size);
			i++;
		}
		free(vector->elements);
		vector->elements = new_elements;
	}
	ft_memcpy(vector->elements + vector->size * vector->elem_size, \
		elem, vector->elem_size);
	return (vector->size++, 0);
}
