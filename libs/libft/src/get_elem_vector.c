/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:34:33 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/12/16 23:34:33 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*get_elem_vector(t_vector *vector, size_t index)
{
	if (index < vector->size)
		return ((char *)vector->elements + index * vector->elem_size);
	else
		return (NULL);
}
