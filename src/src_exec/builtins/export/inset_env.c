/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:01:46 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/25 15:04:49 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_builtins.h"

int	add_env(char *arg, t_vector *env_vector)
{
	t_env	env;

	if (get_env_line(arg, &env) == 1)
		return (1);
	add_vector(env_vector, &env, free_env_line);
	return (0);
}

static void	free_line(t_env *env)
{
	free(env->name);
	free(env->value);
}

int	replace_env(t_vector *env_vector, char *arg)
{
	t_env	env;
	t_env	*line;
	int		i;

	i = 0;
	if (get_env_line(arg, &env) == 1)
		return (1);
	line = get_elem_vector(env_vector, i);
	while (line != NULL)
	{
		if (ft_strcmp(env.name, line->name) == 0)
		{
			if (env.equal == 0)
				return (free_line(&env), 0);
			free(line->value);
			line->value = env.value;
			line->equal = env.equal;
			free(env.name);
			return (0);
		}
		i++;
		line = get_elem_vector(env_vector, i);
	}
	free_line(&env);
	return (2);
}
