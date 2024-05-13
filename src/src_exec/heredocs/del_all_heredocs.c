/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_all_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:07:54 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/13 20:07:54 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	del_all_heredocs(t_tree *node)
{
	if (node->left != NULL)
		del_all_heredocs(node->left);
	if (node->right != NULL)
		del_all_heredocs(node->right);
	if (node->operand == DOUBLE_IN)
	{
		if (unlink(node->name) == -1)
			if (errno != ENOENT)
				perror("minishell: unlink");
	}
}
