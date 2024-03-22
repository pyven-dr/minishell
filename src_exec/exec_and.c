/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:52:25 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/21 02:52:25 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	check_id(int id)
{
	int status;

	if (id < 0)
		return (id);
	else if (id > 0)
	{
		waitpid(id, &status, 0);
		if (WEXITSTATUS(status) != 0)
			return (status);
	}
	return (0);
}

int	exec_and(t_tree *node)
{
	pid_t	id;

	id = exec(node->left);
	if (check_id(id) != 0)
		return (id);
	id = exec(node->right);
	return (check_id(id));
}