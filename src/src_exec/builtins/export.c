/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:26:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 18:00:57 by pyven-dr         ###   ########.fr       */
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
		if (ft_printf(STDOUT_FILENO, "declare -x %s=%s\n", line->name, line->value) == -1)
			return(1);
		i++;
		line = get_elem_vector(env, i);
	}
	return (0);
}

int	check_arg(char *arg)
{
	int	i;

	i = 1;
	if (ft_isalpha(arg[i]) == 0 && arg[i] != '_')
		return (1);
	while (arg[i] != '\0')
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (1);
		if(arg[i] == '=')
			return (0);
		i++;
	}
	return (0);
}

int	export(char **args, t_utils *utils)
{
	int	arg_nb;
	int	i;

	i = 0;
	arg_nb = nb_args(args);
	if (arg_nb == 1)
		if (display_env(utils->env_vector) == 1)
			return (1);
	while (args[i] != NULL)
	{
		if (check_arg(args[i]) == 1)
		{
		}
		i++;
	}
	return (0);
}