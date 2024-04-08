/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:46:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/08 20:46:16 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	env(char **env)
{
	int i;

	i = 0;
	if (env == NULL)
		return (0);
	while (env[i] != NULL)
	{
		if (ft_putendl_fd(env[i], STDOUT_FILENO) == 1)
			return (1);
		i++;
	}
	return (0);
}