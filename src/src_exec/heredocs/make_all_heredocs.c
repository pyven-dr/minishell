/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all_heredocs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:32:00 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/01 01:32:00 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	make_all_heredocs(t_tree *node)
{
	char	*name;

	if (node->left != NULL)
	{
		if (make_all_heredocs(node->left) == 1)
			return (1);
	}
	if (node->right != NULL)
	{
		if (make_all_heredocs(node->right) == 1)
			return (1);
	}
	if (node->operand == DOUBLE_IN)
	{
		name = create_heredoc(node->name);
		if (name == NULL)
			return (1);
		free(node->name);
		node->name = name;
	}
	return (0);
}
