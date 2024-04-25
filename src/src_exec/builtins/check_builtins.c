/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 05:08:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 12:32:04 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	check_builtins(char **cmd, t_utils *utils)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (echo(cmd));
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		return (pwd());
	else if (ft_strcmp(cmd[0], "exit") == 0)
		exit_builtin(cmd, utils);
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (env(utils->env_vector));
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (unset(cmd, utils));
	else if (ft_strcmp(cmd[0], "export") == 0)
		return (export(cmd, utils));
	return (-127);
}