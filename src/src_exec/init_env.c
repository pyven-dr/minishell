/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:21:30 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/25 14:57:01 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	fill_env(char *line, t_vector *env)
{
	t_env	res;
	int		i;

	i = 0;
	res.equal = 1;
	while (line[i] != '=')
		i++;
	line[i] = '\0';
	i++;
	res.name = ft_strdup(line);
	if (res.name == NULL)
		return (1);
	res.value = ft_strdup(&line[i]);
	if (res.value == NULL)
	{
		free(res.name);
		return (1);
	}
	line[i - 1] = '=';
	if (add_vector(env, &res, free_env_line) == -1)
		return (free_env_line(&res), 1);
	return (0);
}

static int	add_env_exit(t_vector *env)
{
	t_env	exit_val;

	exit_val.name = ft_strdup("?");
	if (exit_val.name == NULL)
		return (1);
	exit_val.value = ft_strdup("0");
	if (exit_val.value == NULL)
	{
		free(exit_val.name);
		return (1);
	}
	exit_val.equal = 0;
	if (add_vector(env, &exit_val, free_env_line) == -1)
		return (free_env_line(&exit_val), 1);
	return (0);
}

int	init_env(t_utils *utils, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (fill_env(envp[i], utils->env_vector) == 1)
		{
			del_vector(utils->env_vector, free_env_line);
			return (1);
		}
		i++;
	}
	if (add_env_exit(utils->env_vector) == 1)
	{
		del_vector(utils->env_vector, free_env_line);
		return (1);
	}
	return (0);
}
