/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:01:47 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/07 15:48:59 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parsing.h"

static void	init_tab(t_exec_funcs tab[7])
{
	tab[0] = exec_and;
	tab[1] = exec_or;
	tab[2] = exec_pipe;
	tab[3] = exec_simple_in;
	tab[4] = exec_double_in;
	tab[5] = exec_simple_out;
	tab[6] = exec_double_out;
}

int	cmd_not_found(char **split_cmd, t_utils *utils)
{
	if (change_exit_val(127, utils) == -1)
		return (-1);
	free_cmd(split_cmd + 1);
	free(split_cmd);
	return (-127);
}

int	exec(t_tree *node, t_utils *utils)
{
	t_exec_funcs	exec_funcs_tab[7];
	char			**split_cmd;
	int				ret_value;

	init_tab(exec_funcs_tab);
	if (node->operand == CMD)
	{
		split_cmd = expand(node->name, utils->env_vector);
		if (split_cmd == NULL)
			return (-1);
		ret_value = check_builtins(split_cmd, utils);
		if (ret_value != -127)
		{
			if (change_exit_val(ret_value, utils) == -1)
				return (-1);
			return (free_tab(split_cmd), ret_value);
		}
		split_cmd[0] = get_cmd_path(split_cmd[0], utils->env_vector);
		if (split_cmd[0] == NULL)
			return (cmd_not_found(split_cmd, utils));
		return (exec_cmd(split_cmd, utils));
	}
	return (exec_funcs_tab[node->operand - 1](node, utils));
}
