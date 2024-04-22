/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:26:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/22 12:50:28 by pyven-dr         ###   ########.fr       */
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

int	check_arg(char *arg)
{
	int	i;

	i = 1;
	if (ft_isalpha(arg[0]) == 0 && arg[0] != '_')
		return (1);
	while (arg[i] != '\0')
	{
		if (arg[i] == '=')
			return (0);
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

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

int	add_env(char *arg, t_vector *env_vector)
{
	t_env	env;

	if (get_env_line(arg, &env) == 1)
		return (1);
	add_vector(env_vector, &env, free_env_line);
	return (0);
}

void free_line(t_env *env)
{
	free(env->name);
	free(env->value);
}

int	check_env(t_vector *env_vector, char *arg)
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

int	export(char **args, t_utils *utils)
{
	int	arg_nb;
	int	i;
	int	return_val;
	int	is_insert;

	i = 1;
	return_val = 0;
	arg_nb = nb_args(args);
	if (arg_nb == 1)
	{
		if (display_env(utils->env_vector) == 1)
			return (1);
		return (0);
	}
	while (args[i] != NULL)
	{
		if (check_arg(args[i]) == 1)
		{
			return_val = 1;
			if (ft_printf(2, "export: '%s': not a valid identifier\n", \
				args[i]) == -1)
				return (1);
		}
		else
		{
			is_insert = check_env(utils->env_vector, args[i]);
			if (is_insert == 1)
				return (1);
			if (is_insert == 2)
				if (add_env(args[i], utils->env_vector) == 1)
					return (1);
		}
		i++;
	}
	return (return_val);
}
