/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:35:50 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/27 13:10:42 by sabitbol         ###   ########.fr       */
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
	return (node);
}

void	insert_node(t_tree *node, t_operand operand, char *name)
{
	// if (!node->parent)
	// {
	// 	node->parent = new_node(NULL, operand, name);
	// }
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

void	fill_tree(t_tree **tree, t_operand operand, t_parenthes *save, char **line)
{
	if (operand == CMD)
		fill_cmd(tree, operand, line);
	if (operand == PIPE)
		fill_pipe(tree, operand, save);
	if (operand == AND || operand == OR)
		fill_operator(tree, operand, save);
	if (operand == SIMPLE_IN || operand == DOUBLE_IN || \
	operand == SIMPLE_OUT || operand == DOUBLE_OUT)
		fill_file(tree, operand, line);
}

void	free_tree(t_tree **tree)
{
	if (!*tree)
		;
	else
	{
		free_tree(&(*tree)->right);
		free_tree(&(*tree)->left);
		if ((*tree)->operand == PIPE || \
		(*tree)->operand == AND || (*tree)->operand == OR)
			;
		else
			free((*tree)->name);
		free(*tree);
	}
}

void	print_tree(t_tree *tree, int space)
{
	int	c;

	c = space;
	if (!tree)
	{
		while (c-- > 0)
			printf(" ");
		printf("NULL\n");
	}
	else
	{
		while (c-- > 0)
			printf(" ");
		print_node(tree);

		print_tree(tree->left, space + 5);

		print_tree(tree->right, space + 5);
	}
}

void	print_node(t_tree *node)
{
	if (node->operand == AND)
		printf("&&\n");
	else if (node->operand == OR)
		printf("||\n");
	else if (node->operand == PIPE)
		printf("|\n");
	else if (node->operand == CMD)
		printf("CMD : %s\n", node->name);
	else if (node->operand == SIMPLE_IN)
		printf("< : %s\n", node->name);
	else if (node->operand == DOUBLE_IN)
		printf("<< : %s\n", node->name);
	else if (node->operand == SIMPLE_OUT)
		printf("> : %s\n", node->name);
	else if (node->operand == DOUBLE_OUT)
		printf(">> : %s\n", node->name);
}
