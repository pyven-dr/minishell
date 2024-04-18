/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:26:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 12:41:29 by pyven-dr         ###   ########.fr       */
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
		if (ft_putstr_fd("declare -x ", STDOUT_FILENO) == 1)
			return (1);	
		if (ft_putstr_fd(line->name, STDOUT_FILENO) == 1)
			return (1);
		if (ft_putchar_fd('=', STDOUT_FILENO) == 1)
			return (1);
		if (ft_putendl_fd(line->value, STDOUT_FILENO == 1))
			return (1);
		i++;
		line = get_elem_vector(env, i);
	}
	return (0);
}

int	export(char **args, t_utils *utils)
{
	int	arg_nb;
	
	arg_nb = nb_args(args);
	if (arg_nb == 1)
		if (display_env(utils->env_vector) == 1)
			return (1);
	return (0);
}