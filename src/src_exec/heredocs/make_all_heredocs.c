/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all_heredocs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 01:32:00 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/15 18:55:05 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	make_all_heredocs(t_tree *node, t_vector *env)
{
	char	*name;

	if (node->left != NULL)
	{
		if (make_all_heredocs(node->left, env) == 1)
			return (1);
	}
	if (node->right != NULL)
	{
		if (make_all_heredocs(node->right, env) == 1)
			return (1);
	}
	if (node->operand == DOUBLE_IN)
	{
		name = create_heredoc(node->name, env);
		if (name == NULL)
			return (1);
		free(node->name);
		node->name = name;
	}
	return (0);
}
