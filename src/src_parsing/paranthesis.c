/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paranthesis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:58:04 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/03 19:21:33 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	save_parenthesis(t_parsing *pars, char **line)
{
	t_parenthes	*to_save;

	if (pars->tree && pars->tree->operand != AND && \
	pars->tree->operand != OR && pars->tree->operand != PIPE)
		return (clean_continue(pars, line, 2), false);
	while (pars->save && pars->save->next)
		pars->save = pars->save->next;
	to_save = malloc(sizeof(t_parenthes));
	if (!to_save)
		return (clean_continue(pars, line, 1));
	to_save->next = NULL;
	to_save->p = pars->tree;
	if (!pars->save)
		pars->save = to_save;
	else
		pars->save->next = to_save;
	return (true);
}

t_tree	*get_last_save(t_parsing *pars)
{
	t_tree		*p;
	t_parenthes	*head;

	head = pars->save;
	while (pars->save->next && pars->save->next->next)
		pars->save = pars->save->next;
	if (!pars->save->next)
	{
		p = pars->save->p;
		free(pars->save);
		pars->save = NULL;
	}
	else
	{
		p = pars->save->next->p;
		free(pars->save->next);
		pars->save->next = NULL;
	}
	if (pars->save)
		pars->save = head;
	pars->parenthes = true;
	return (p);
}
