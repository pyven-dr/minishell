/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:45:40 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/10 17:45:40 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	free_env(t_vector *env)
{
	/*size_t	i;
	t_env	*line;

	i = 1;
	line = get_elem_vector(env, 0);
	while (i < env->size)
	{
		free(line->value);
		free(line->name);
		free(line);
		line = get_elem_vector(env, i);
		i++;
	}*/
	del_vector(env);
}
