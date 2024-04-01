/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:58:12 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/01 02:35:41 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void    free_save(t_parenthes **save)
{
    if (!*save)
        ;
    else
    {
        free_save(&(*save)->next);
        free(*save);
    }
}

void    clean_exit(t_parsing *pars, char **line, int exit_code)
{
    free_save(&pars->save);
    free_tree(&pars->tree);
    *line = pars->head_line;
    free(*line);
    exit(exit_code);
}
