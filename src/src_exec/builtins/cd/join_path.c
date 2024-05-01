/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:56:37 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/01 02:56:37 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*join_path(char **components, int last, int nb_components)
{
	int		i;
	char	*path;
	char	*temp;

	i = 0;
	path = NULL;
	while (i < nb_components && i < last)
	{
		if (components[i] != NULL)
		{
			temp = path;
			path = ft_strjoin(temp, "/");
			free(temp);
			if (path == NULL)
				return (NULL);
			temp = path;
			path = ft_strjoin(temp, components[i]);
			free(temp);
			if (path == NULL)
				return (NULL);
		}
		i++;
	}
	if (path == NULL)
	{
		path = ft_strdup("/");
		if (path == NULL)
			return (NULL);
	}
	return (path);
}
