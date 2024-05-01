/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dotdot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:54:17 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/01 02:54:17 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	check_dotdot(char **component, int index_component)
{
	if (ft_strcmp(component[index_component], "..") != 0)
		return (1);
	if (index_component == 0)
		return (1);
	while (component[index_component - 1] == NULL && index_component - 1 > 0)
		index_component--;
	if (component[index_component - 1] != NULL)
	{
	if (ft_strcmp(component[index_component - 1], "..") == 0)
		return (1);
	}
	return (0);
}

int	remove_dotdot(char ***components, int nb_components, char *directory)
{
	int	i;

	i = 0;
	while (i < nb_components)
	{
		if ((*components)[i] != NULL)
		{
		if (check_dotdot(*components, i) == 0)
		{
			if (check_file(*components, i, nb_components, directory) == 1)
				return (1);
			free((*components)[i]);
			(*components)[i] = NULL;
			while ((*components)[i - 1] == NULL && i - 1 > 0)
				i--;
			free((*components)[i - 1]);
			(*components)[i - 1] = NULL;
		}
		}
		i++;
	}
	return (0);
}