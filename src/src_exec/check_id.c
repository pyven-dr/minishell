/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:00:20 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/23 00:00:20 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	check_status(int status, t_utils *utils)
{
	if (WIFSIGNALED(status) == true)
	{
		if (print_sig_cmd() == 1)
			return (-1);
		return (check_sig(utils));
	}
	else if (WEXITSTATUS(status) != 0)
	{
		if (change_exit_val(WEXITSTATUS(status), utils) == 1)
			return (-1);
		return (WEXITSTATUS(status) * -1);
	}
	else
	{
		if (change_exit_val(0, utils) == 1)
			return (-1);
		return (0);
	}
}

static int	check_pipe(int id, t_tree *node)
{
	if ((id == -130 || id == -131) && (node->left->operand == PIPE \
		|| node->right->operand == PIPE))
	{
		if (id == -130)
		{
			if (ft_putchar_fd('\n', STDERR_FILENO) == -1)
				return (-1);
		}
		else if (id == -131)
		{
			if (ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO) == -1)
				return (-1);
		}
	}
	return (id);
}

int	check_id(int id, t_utils *utils, t_tree *node)
{
	int	status;

	id = check_pipe(id, node);
	if (id < 0)
		return (id);
	else if (id > 0)
	{
		sig_end_exec();
		if (waitpid(id, &status, 0) == -1)
		{
			change_exit_val(1, utils);
			return (-1);
		}
		return (check_status(status, utils));
	}
	if (change_exit_val(0, utils) == 1)
		return (-1);
	return (0);
}
