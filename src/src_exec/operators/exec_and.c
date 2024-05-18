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

int	exec_and(t_tree *node, t_utils *utils)
{
	pid_t	id;
	int 	status;

	id = exec(node->left, utils);
	status = check_id(id, utils);
	if (status != 0)
		return (status);
	id = exec(node->right, utils);
	return (check_id(id, utils));
}
