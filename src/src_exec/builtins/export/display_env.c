/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:58:33 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/25 14:59:03 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	display_env(t_vector *env)
{
	int		i;
	t_env	*line;

	i = 0;
	line = get_elem_vector(env, i);
	while (line != NULL)
	{
		if (line->equal == 1)
		{
			if (ft_printf(STDOUT_FILENO, "declare -x %s=\"%s\"\n", \
				line->name, line->value) == -1)
				return (1);
		}
		else
		{
			if (ft_printf(STDOUT_FILENO, "declare -x %s\n", \
				line->name) == -1)
				return (1);
		}
		i++;
		line = get_elem_vector(env, i);
	}
	return (0);
}
