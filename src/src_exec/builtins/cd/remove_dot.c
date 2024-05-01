/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:53:14 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/01 02:53:14 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	remove_dot(char ***components, int nb_components)
{
	int	i;

	i = 0;
	while (i < nb_components)
	{
		if (ft_strcmp((*components)[i], ".") == 0)
		{
			free((*components)[i]);
			(*components)[i] = NULL;
		}
		i++;
	}
}
