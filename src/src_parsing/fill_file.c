/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:03:49 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/16 22:19:01 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	add_file_to_operator(t_parsing *pars, char **line);
static bool	add_file_to_cmd(t_parsing *pars, char **line);
static bool	add_file_at_top(t_parsing *pars, char **line);
static bool	add_file_after_parenthesis(t_parsing *pars, char **line);

bool	fill_file(t_parsing *pars, char **line)
{
	if (!pars->tree)
	{
		pars->tree = new_node(NULL, pars->operand, \
		strdup_to_next_space(line, pars));
		if (!pars->tree)
			return (clean_continue(pars, line, 1));
		if (!*pars->tree->name)
			return (clean_continue(pars, line, 2));
	}
	else if ((pars->tree->operand == AND || pars->tree->operand == OR \
	|| pars->tree->operand == PIPE) && !pars->parenthes)
		return (add_file_to_operator(pars, line));
	else if (pars->tree->operand != CMD && !pars->parenthes)
		return (add_file_to_cmd(pars, line));
	else if ((!pars->tree->parent && pars->parenthes != 1) \
	|| pars->parenthes == 2)
		return (add_file_at_top(pars, line));
	else
		return (add_file_after_parenthesis(pars, line));
	return (true);
}

static bool	add_file_to_operator(t_parsing *pars, char **line)
{
	char	*name;

	name = strdup_to_next_space(line, pars);
	if (name == NULL)
		return (NULL);
	pars->tree->right = new_node(pars->tree, pars->operand, name);
	if (!pars->tree->right)
		return (clean_continue(pars, line, 1));
	pars->tree = pars->tree->right;
	if (!*pars->tree->name)
		return (clean_continue(pars, line, 2));
	return (true);
}

static bool	add_file_to_cmd(t_parsing *pars, char **line)
{
	char	*name;

	name = strdup_to_next_space(line, pars);
	if (name == NULL)
		return (NULL);
	pars->tree->left = new_node(pars->tree, pars->operand, name);
	if (!pars->tree->left)
		return (clean_continue(pars, line, 1));
	pars->tree = pars->tree->left;
	if (!*pars->tree->name)
		return (clean_continue(pars, line, 2));
	return (true);
}

static bool	add_file_at_top(t_parsing *pars, char **line)
{
	char	*name;

	name = strdup_to_next_space(line, pars);
	if (name == NULL)
		return (NULL);
	pars->tree->parent = new_node(NULL, pars->operand, name);
	if (!pars->tree->parent)
		return (clean_continue(pars, line, 1));
	pars->tree->parent->left = pars->tree;
	if (!*pars->tree->parent->name)
		return (clean_continue(pars, line, 2));
	return (true);
}

static bool	add_file_after_parenthesis(t_parsing *pars, char **line)
{
	if (pars->parenthes)
	{
		pars->tree = pars->tree->right;
		pars->parenthes = 0;
	}
	insert_node(pars->tree, pars->operand, line, pars);
	if (!*pars->tree->parent->name)
		return (clean_continue(pars, line, 2));
	return (true);
}
