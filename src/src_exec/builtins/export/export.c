/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:26:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/25 15:21:03 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	insert_in_env(char *arg, t_vector *env_vector)
{
	int	is_insert;

	is_insert = replace_env(env_vector, arg);
	if (is_insert == 1)
		return (1);
	if (is_insert == 2)
		if (add_env(arg, env_vector) == 1)
			return (1);
	return (0);
}

int	export(char **arg, t_utils *utils)
{
	int	arg_nb;
	int	i;
	int	return_val;

	i = 1;
	return_val = 0;
	arg_nb = nb_args(arg);
	if (arg_nb == 1)
		return (display_env(utils->env_vector));
	while (arg[i] != NULL)
	{
		if (check_arg_env(arg[i]) == 1)
		{
			return_val = 1;
			if (ft_printf(2, \
			"minishell: export: '%s': not a valid identifier\n", arg[i]) == -1)
				return (-1);
		}
		else
			if (insert_in_env(arg[i], utils->env_vector) == 1)
				return (-1);
		i++;
	}
	return (return_val);
}
