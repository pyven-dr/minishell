/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_operand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:31:20 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/02 18:38:47 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	fill_pipe(t_parsing *pars, char **line)
{
	t_parenthes	*save;

	if (!pars->tree || (!pars->parenthes && (pars->tree->operand == AND \
	|| pars->tree->operand == OR || pars->tree->operand == PIPE)))
		clean_exit(pars, line, 2);
	if (pars->parenthes)
		if (pars->tree->operand == AND || pars->tree->operand == OR)
			pars->tree = pars->tree->right;
	pars->parenthes = 0;
	save = pars->save;
	while (save && save->next)
		save = save->next;
	while ((!save || save->p != pars->tree->parent) && pars->tree->parent \
	&& pars->tree->parent->operand != AND && pars->tree->parent->operand != OR)
		pars->tree = pars->tree->parent;
	if (pars->tree->parent)
		insert_node(pars->tree, pars->operand, line, pars);
	else
	{
		pars->tree->parent = new_node(NULL, pars->operand, NULL);
		pars->tree->parent->left = pars->tree;
	}
	if (!pars->tree->parent)
		clean_exit(pars, line, 1);
	pars->tree = pars->tree->parent;
}

void	fill_operator(t_parsing *pars, char **line)
{
	t_parenthes	*save;

	if (!pars->tree || (!pars->parenthes && (pars->tree->operand == AND \
	|| pars->tree->operand == OR || pars->tree->operand == PIPE)))
		clean_exit(pars, line, 2);
	save = pars->save;
	while (save && save->next)
		save = save->next;
	while ((!save || save->p != pars->tree->parent) && pars->tree->parent)
		pars->tree = pars->tree->parent;
	if (pars->tree->parent)
		insert_node(pars->tree, pars->operand, line, pars);
	else
	{
		pars->tree->parent = new_node(NULL, pars->operand, NULL);
		if (!pars->tree->parent)
			clean_exit(pars, line, 1);
		pars->tree->parent->left = pars->tree;
	}
	pars->tree = pars->tree->parent;
	if (pars->parenthes)
		pars->parenthes = 0;
}
