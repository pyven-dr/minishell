/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:04:21 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/13 19:14:54 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_getenv(char *name, t_vector *env_vector)
{
	t_env	*line;
	int		i;

	i = 0;
	line = get_elem_vector(env_vector, 0);
	while (line != NULL)
	{
		if (ft_strcmp(line->name, name) == 0)
			return (i);
		i++;
		line = get_elem_vector(env_vector, i);
	}
	return (-1);
}
