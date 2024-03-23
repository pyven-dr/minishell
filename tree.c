/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:35:50 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/23 04:01:45 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tree	*new_node(t_tree *parent, t_operand operand, char *name)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->right = NULL;
	node->left = NULL;
	node->name = name;
	node->operand = operand;
}

void	insert_node(t_tree *node, t_operand operand, char *name)
{
	if (node == node->parent->left)
	{
		node->parent->left = NULL;
		node->parent->left = new_node(node->parent, operand, name);
		if (!node->parent->left)
			exit(44);
		node->parent->left->left = node;
		node->parent = node->parent->left;
	}
	else if (node == node->parent->right)
	{
		node->parent->right = NULL;
		node->parent->right = new_node(node->parent, operand, name);
		if (!node->parent->right)
			exit(44);
		node->parent->right->left = node;
		node->parent = node->parent->right;
	}
}
