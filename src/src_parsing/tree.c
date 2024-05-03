/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:35:50 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/03 14:11:18 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	insert_to_right(t_tree *node, t_operand operand, \
char **line, t_parsing *pars);
static void	insert_to_left(t_tree *node, t_operand operand, \
char **line, t_parsing *pars);

t_tree	*new_node(t_tree *parent, t_operand operand, char *name)
{
	t_tree	*node;

	if ((operand == CMD || operand == SIMPLE_IN || operand == SIMPLE_OUT || \
	operand == DOUBLE_IN || operand == DOUBLE_OUT) && !name)
		return (NULL);
	node = malloc(sizeof(t_tree));
	if (!node)
	{
		if (name)
			free(name);
		return (NULL);
	}
	node->name = name;
	node->parent = parent;
	node->right = NULL;
	node->left = NULL;
	node->operand = operand;
	return (node);
}

void	insert_node(t_tree *node, t_operand operand, \
char **line, t_parsing *pars)
{
	if (node == node->parent->left)
		insert_to_left(node, operand, line, pars);
	else if (node == node->parent->right)
		insert_to_right(node, operand, line, pars);
}

static void	insert_to_right(t_tree *node, t_operand operand, \
char **line, t_parsing *pars)
{
	node->parent->right = NULL;
	if (operand == AND || operand == OR || operand == PIPE)
		node->parent->right = new_node(node->parent, operand, NULL);
	else
		node->parent->right = new_node(node->parent, operand, \
		strdup_to_next_space(line, pars));
	if (!node->parent->right)
		clean_exit(pars, line, 1);
	node->parent->right->left = node;
	node->parent = node->parent->right;
}

static void	insert_to_left(t_tree *node, t_operand operand, \
char **line, t_parsing *pars)
{
	node->parent->left = NULL;
	if (operand == AND || operand == OR || operand == PIPE)
		node->parent->left = new_node(node->parent, operand, NULL);
	else
		node->parent->left = new_node(node->parent, operand, \
		strdup_to_next_space(line, pars));
	if (!node->parent->left)
		clean_exit(pars, line, 1);
	node->parent->left->left = node;
	node->parent = node->parent->left;
}

bool	fill_tree(t_parsing *pars, char **line)
{
	if (pars->operand == CMD)
		return (fill_cmd(pars, line));
	else if (pars->operand == PIPE)
		return (fill_pipe(pars, line));
	else if (pars->operand == AND || pars->operand == OR)
		return (fill_operator(pars, line));
	else
		return (fill_file(pars, line));
}

//---------------PRINT TREE FUNCTIUN----------------//
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
		print_tree(tree->left, space + 5);
		while (c-- > 0)
			printf(" ");
		print_node(tree);
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
//---------------PRINT TREE FUNCTIUN----------------//
