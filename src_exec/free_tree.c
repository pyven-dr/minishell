/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 05:11:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/05 05:11:26 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_tree *find_root(t_tree *node)
{
	while (node->parent != NULL)
		node = node->parent;
	return (node);
}

void	free_tree(t_tree *node)
{
	if (node->left != NULL)
		free_tree(node->left);
	if (node->right != NULL)
		free_tree(node->right);
	free(node);
}