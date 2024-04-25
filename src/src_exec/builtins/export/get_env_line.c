/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:54:54 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/25 15:04:58 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	get_env_line(char *arg, t_env *env)
{
	int		i;

	i = 0;
	env->equal = 0;
	while (arg[i] != '\0' && arg[i] != '=')
		i++;
	if (arg[i] == '=')
	{
		env->equal = 1;
		arg[i] = '\0';
		i++;
	}
	env->name = ft_strdup(arg);
	if (env->name == NULL)
		return (1);
	env->value = ft_strdup(&arg[i]);
	if (env->value == NULL)
	{
		free(env->name);
		return (1);
	}
	if (env->equal == 1)
		arg[i - 1] = '=';
	return (0);
}
