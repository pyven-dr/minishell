/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:01:47 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/02 01:50:19 by sabitbol         ###   ########.fr       */
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

int	exec(t_tree *node, t_utils *utils)
{
	t_exec_funcs	exec_funcs_tab[7];
	char			**split_cmd;
	int				ret_value;

	init_tab(exec_funcs_tab);
	if (node->operand == CMD)
	{
		split_cmd = expand(node->name, utils->env_vector);
		if (!split_cmd)
			return (-1);
		ret_value = check_builtins(split_cmd, utils);
		if (ret_value != -127)
			return (free_tab(split_cmd), ret_value);
		split_cmd[0] = get_cmd_path(split_cmd[0], utils->env_vector);
		if (split_cmd[0] == NULL)
		{
			free_cmd(split_cmd + 1);
			free(split_cmd);
			return (-127);
		}
		return (exec_cmd(split_cmd, utils));
	}
	return (exec_funcs_tab[node->operand - 1](node, utils));
}
