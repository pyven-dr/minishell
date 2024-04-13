/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:46:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/13 19:30:55 by pyven-dr         ###   ########.fr       */
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
		if (line->value != NULL)
		{
			if (ft_putstr_fd(line->name, STDOUT_FILENO) == 1)
				return (1);
			if (ft_putchar_fd('=', STDOUT_FILENO) == 1)
				return (1);
			if (ft_putendl_fd(line->value, STDOUT_FILENO == 1))
				return (1);
		}
		i++;
		line = get_elem_vector(env, i);
	}
	return (0);
}
