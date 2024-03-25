/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paranthesis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:58:04 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/24 22:27:59 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    save_parenthesis(t_parenthes *save, t_tree *node)
{
	t_parenthes	*to_save;

	while (save && save->next)
		save = save->next;
	to_save = malloc(sizeof(t_parenthes));
	if (!to_save)
	{
		exit(00000);
	}
	to_save->p = node;
	if (!save)
		save = to_save;
	else
		save->next = to_save;
}

t_tree	*get_last_save(t_parenthes **save)
{
	t_tree		*p;
	t_parenthes	*head;

	head = *save;
	while ((*save)->next && (*save)->next->next)
		*save = (*save)->next;
	if (!(*save)->next)
	{
		p = (*save)->p;
		free(*save);
		*save = NULL;
	}
	else
	{
		p = (*save)->next->p;
		free((*save)->next);
		(*save)->next = NULL;
	}
	*save = head;
	return (p);
}
