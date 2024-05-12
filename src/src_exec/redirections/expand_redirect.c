/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:48:30 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/10 18:48:30 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parsing.h"

int	expand_redirect(t_tree *node, t_vector *env_vector)
{
	char	**expanded_node;

	expanded_node = expand(node->name, env_vector);
	if (expanded_node == NULL)
		return (1);
	if (nb_args(expanded_node) > 1)
	{
		ft_putstr_fd("minishell: ambiguous redirect\n", 2);
		free_tab(expanded_node);
		return (1);
	}
	free(node->name);
	node->name = ft_strdup(expanded_node[0]);
	free_tab(expanded_node);
	if (node->name == NULL)
		return (1);
	return (0);
}
