/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:19:45 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/12/16 20:19:45 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*new_vector(size_t capacity, size_t elem_size)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->elements = ft_calloc(capacity, elem_size);
	if (!vector->elements)
		return (free(vector), NULL);
	vector->capacity = capacity;
	vector->size = 0;
	vector->elem_size = elem_size;
	return (vector);
}
