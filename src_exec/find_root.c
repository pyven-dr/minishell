/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 05:54:47 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/05 05:54:47 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_tree	*find_root(t_tree *node)
{
	while (node->parent != NULL)
		node = node->parent;
	return (node);
}
