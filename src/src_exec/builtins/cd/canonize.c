/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:12:38 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/30 23:12:38 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*add_fisrt_slash(char *curpath, int start_slash)
{
	char	*temp;

	if (start_slash == 1)
	{
		temp = curpath;
		curpath = ft_strjoin("/", temp);
		free(temp);
		if (curpath == NULL)
			return (NULL);
	}
	return (curpath);
}

void	free_components(char **components, int nb_components)
{
	int i;

	i = 0;
	while (i < nb_components)
	{
		printf("%s\n",components[i]);
		free(components[i]);
		i++;
	}
	free(components[i]);
	free(components);
}

char	*canonize(char *curpath, char *directory)
{
	int		nb_components;
	int		start_slash;
	char	**components;

	start_slash = 0;
	if (curpath[0] == '/' && curpath[1] == '/')
		start_slash = 1;
	components = ft_split(curpath, '/');
	free(curpath);
	if (components == NULL)
		return (NULL);
	nb_components = nb_args(components);
	remove_dot(&components, nb_components);
	if (remove_dotdot(&components, nb_components, directory) == 1)
		return (free_components(components, nb_components), NULL);
	curpath = join_path(components, nb_components, nb_components);
	free_components(components, nb_components);
	if (curpath == NULL)
		return (NULL);
	curpath = add_fisrt_slash(curpath, start_slash);
	if (curpath == NULL)
		return (NULL);
	return (curpath);
}