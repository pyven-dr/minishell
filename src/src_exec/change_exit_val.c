/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_exit_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 04:33:24 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/04 04:33:24 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	change_exit_val(int val, t_utils *utils)
{
	char	*char_val;
	int		exit_index;
	t_env	*exit_env;

	char_val = ft_itoa(val);
	if (char_val == NULL)
		return (1);
	exit_index = ft_getenv("?", utils->env_vector);
	exit_env = get_elem_vector(utils->env_vector, exit_index);
	free(exit_env->value);
	exit_env->value = char_val;
	return (0);
}
