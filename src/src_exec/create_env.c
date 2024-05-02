/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:09:36 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/02 01:43:53 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*fill_tab_with_env(t_env *env);

char	**create_env(t_vector *env_vector)
{
	char	**tab;
	t_env	*env;
	size_t	i;

	i = 0;
	env = get_elem_vector(env_vector, i);
	if (!env)
		return (NULL);
	tab = malloc((env_vector->size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (env)
	{
		tab[i] = fill_tab_with_env(env);
		if (!tab[i])
		{
			while (i-- > 0)
				free(tab[i]);
			return (free(tab), NULL);
		}
		i++;
		env = get_elem_vector(env_vector, i);
	}
	tab[i] = NULL;
	return (tab);
}

static char	*fill_tab_with_env(t_env *env)
{
	char	*line;
	size_t	len_name;
	size_t	len_value;

	len_name = ft_strlen(env->name);
	len_value = ft_strlen(env->value);
	line = malloc(len_name + len_value + 2);
	if (!line)
		return (NULL);
	ft_memmove(line, env->name, len_name);
	line[len_name] = '=';
	ft_memmove(line + len_name + 1, env->value, len_value);
	line[len_name + len_value + 1] = '\0';
	return (line);
}
