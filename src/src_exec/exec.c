/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:01:47 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/20 00:01:47 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <dirent.h>

int	exec(t_tree *node, t_utils *utils)
{
	char	**split_cmd;
	int		ret_value;

	if (node->operand == CMD)
	{
		split_cmd = ft_split(node->name, ' '); //Temporary split waiting for expand
		ret_value = check_builtins(split_cmd, utils);
		if (ret_value != -127)
		{
			free_cmd(split_cmd);
			free(split_cmd);
			return (ret_value);
		}
		split_cmd[0] = get_cmd_path(split_cmd[0]);
		if (split_cmd[0] == NULL)
		{
			ft_putendl_fd("Command not found", 2);
			free_cmd(split_cmd + 1);
			free(split_cmd);
			return (-127);
		}
		return (exec_cmd(split_cmd, utils));
	}
	else if (node->operand == AND)
		return (exec_and(node, utils));
	else if (node->operand == OR)
		return (exec_or(node, utils));
	else if (node->operand == PIPE)
		return (exec_pipe(node, utils));
	else if (node->operand == SIMPLE_IN)
		return (exec_simple_in(node, utils));
	else if (node->operand == SIMPLE_OUT)
		return (exec_simple_out(node, utils));
	else if (node->operand == DOUBLE_OUT)
		return (exec_double_out(node, utils));
	else if (node->operand == DOUBLE_IN)
		return (exec_double_in(node, utils));
	return (0);
}
