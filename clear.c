/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:58:12 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/01 01:11:55 by sabitbol         ###   ########.fr       */
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
