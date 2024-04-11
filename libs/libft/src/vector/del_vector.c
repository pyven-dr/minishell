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

void	del_vector(t_vector *vector, void (*ft_free) (void *elem))
{
	size_t	i;

	i = 0;
	while (i < vector->size)
	{
		if (ft_free != NULL)
			ft_free(vector->elements + i * vector->elem_size);
		i++;
	}
	free(vector->elements);
	free(vector);
}
