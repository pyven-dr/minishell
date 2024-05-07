/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:19:08 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/13 20:05:04 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	unset(char **args, t_utils *utils)
{
	int	i;
	int	pos;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strcmp(args[i], "?") != 0)
		{
			pos = ft_getenv(args[i], utils->env_vector);
			if (pos != -1)
				del_elem_vector(utils->env_vector, pos, free_env_line);
		}
		i++;
	}
	return (0);
}
