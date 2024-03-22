/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:27:21 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/22 23:27:21 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_or(t_tree *node)
{
	pid_t	id;

	id = exec(node->left);
	if (check_id(id) == 0)
		return (id);
	id = exec(node->right);
	return (check_id(id));
}