/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:58:12 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/16 15:56:54 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"

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
		*tree = NULL;
	}
}

void	free_save(t_parenthes **save)
{
	if (!*save)
		;
	else
	{
		free_save(&(*save)->next);
		free(*save);
	}
}

void	clean_exit(t_parsing *pars, char **line, int exit_code)
{
	if (pars->tree)
		while (pars->tree->parent)
			pars->tree = pars->tree->parent;
	free_save(&pars->save);
	free_tree(&pars->tree);
	*line = pars->head_line;
	free(*line);
	if (exit_code == 1)
		write(2, ERR_MALLOC, 25);
	else if (exit_code == 2)
		write(2, ERR_SYNTHAX, 26);
	else if (exit_code == 3)
	{
		write(2, ERR_UNCLOSED, 42);
		exit_code = 2;
	}
	exit(exit_code);
}

void	free_value(void *value)
{
	char	**line;

	line = value;
	free(*line);
}

void	*clean_continue(t_parsing *pars, char **line, int code)
{
	if (pars->tree)
		while (pars->tree->parent)
			pars->tree = pars->tree->parent;
	free_save(&pars->save);
	free_tree(&pars->tree);
	*line = pars->head_line;
	free(*line);
	if (code == 2)
		write(2, ERR_SYNTHAX, 26);
	else if (code == 3)
		write(2, ERR_UNCLOSED, 42);
	else if (code == 1)
		write(2, ERR_MALLOC, 25);
	return (NULL);
}
