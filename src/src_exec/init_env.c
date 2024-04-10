/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:21:30 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/10 17:21:30 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	fill_env(char *line, t_vector *env)
{
	t_env	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(t_env));
	if (res == NULL)
		return (1);
	while (line[i] != '=')
		i++;
	line[i] = '\0';
	i++;
	res->name = ft_strdup(line);
	if (res->name == NULL)
	{
		free(res);
		return (1);
	}
	res->value = ft_strdup(&line[i]);
	if (res->value == NULL)
	{
		free(res->name);
		free(res);
		return (1);
	}
	line[i - 1] = '=';
	add_vector(env, res);
	return (0);
}

int init_env(t_utils *utils, char **envp)
{
	int 	i;
	t_env	*line;

	i = 0;
	while (envp[i] != NULL)
	{
		if (fill_env(envp[i], utils->env_vector) == 1)
		{
			del_vector(utils->env_vector);
			return (1);
		}
		line = get_elem_vector(utils->env_vector, i);
		if (line == NULL)
			dprintf(2, "NULL\n");
		else
			dprintf(2, "%d %p %p\n",i, line->name, line->value);
		i++;
	}
	return (0);
}
