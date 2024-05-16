/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 05:08:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/16 15:58:56 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	check_builtins(char **cmd, t_utils *utils, t_tree *tree)
{
	t_tree	*root;

	if (cmd[0] != NULL)
	{
		if (ft_strcmp(cmd[0], "echo") == 0)
			return (echo(cmd));
		else if (ft_strcmp(cmd[0], "pwd") == 0)
			return (pwd());
		else if (ft_strcmp(cmd[0], "exit") == 0)
		{
			root = find_root(tree);
			free_tree(&root);
			exit_builtin(cmd, utils);
		}
		else if (ft_strcmp(cmd[0], "env") == 0)
			return (env(utils->env_vector));
		else if (ft_strcmp(cmd[0], "unset") == 0)
			return (unset(cmd, utils));
		else if (ft_strcmp(cmd[0], "export") == 0)
			return (export(cmd, utils));
		else if (ft_strcmp(cmd[0], "cd") == 0)
			return (cd(cmd, utils));
		return (-127);
	}
	return (1);
}
