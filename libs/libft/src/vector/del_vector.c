/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:39:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/12/16 20:39:48 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_vector(t_vector *vector)
{
	size_t	i;

	i = 0;
	while (i - 1 < vector->size)
	{
		free(vector->elements + i * vector->elem_size);
		i++;
	}
	free(vector->elements);
	free(vector);
}
