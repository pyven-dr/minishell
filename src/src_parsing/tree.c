/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:35:50 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/24 19:38:26 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	insert_to_right(t_tree *node, t_operand operand, \
char **line, t_parsing *pars);
static int	insert_to_left(t_tree *node, t_operand operand, \
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

static int	insert_to_right(t_tree *node, t_operand operand, \
char **line, t_parsing *pars)
{
	node->parent->right = NULL;
	if (operand == AND || operand == OR || operand == PIPE)
		node->parent->right = new_node(node->parent, operand, NULL);
	else
		node->parent->right = new_node(node->parent, operand, \
		strdup_to_next_space(line, pars));
	if (!node->parent->right)
	{
		clean_continue(pars, line, 1);
		return (1);
	}
	node->parent->right->left = node;
	node->parent = node->parent->right;
	return (0);
}

static int	insert_to_left(t_tree *node, t_operand operand, \
char **line, t_parsing *pars)
{
	node->parent->left = NULL;
	if (operand == AND || operand == OR || operand == PIPE)
		node->parent->left = new_node(node->parent, operand, NULL);
	else
		node->parent->left = new_node(node->parent, operand, \
		strdup_to_next_space(line, pars));
	if (!node->parent->left)
	{
		clean_continue(pars, line, 1);
		return (1);
	}
	node->parent->left->left = node;
	node->parent = node->parent->left;
	return (0);
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
