/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:46:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 18:10:28 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	env(t_vector *env)
{
	int		i;
	t_env	*line;

	i = 0;
	line = get_elem_vector(env, i);
	while (line != NULL)
	{
		if (line->equal == 1)
			if (ft_printf(STDOUT_FILENO, "%s=%s\n", \
				line->name, line->value) == -1)
				return (1);
		i++;
		line = get_elem_vector(env, i);
	}
	return (0);
}
