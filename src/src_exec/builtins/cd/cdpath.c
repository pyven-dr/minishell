/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdpath.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:38:49 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/28 21:38:49 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	check_path(char *elem, char *path)
{
	struct stat	file;
	char		*join_path;

	join_path = ft_strjoin(elem, path);
	if (join_path == NULL)
		return (1);
	if (stat(join_path, &file) == 0)
	{
		free(join_path);
		if (S_ISDIR(file.st_mode) != 0)
			return (0);
		return (2);
	}
	free(join_path);
	return (2);
}

static void	free_cdpath(char **cdpath)
{
	free_cmd(cdpath);
	free(cdpath);
}

char	*check_cdpath(t_utils *utils, char *directory)
{
	char	**cdpath;
	int		i;
	int		return_val;
	char	*path;

	i = 0;
	cdpath = NULL;
	return_val = split_cdpath(&cdpath, utils);
	if (return_val == 1)
		return (NULL);
	while (return_val != 2 && cdpath[i] != NULL)
	{
		return_val = check_path(cdpath[i], directory);
		if (return_val == 1)
			return (free_cdpath(cdpath), NULL);
		if (return_val == 0)
		{
			path = ft_strjoin(cdpath[i], directory);
			return (free_cdpath(cdpath), path);
		}
		i++;
	}
	if (cdpath != NULL)
		free_cdpath(cdpath);
	return (ft_strdup(directory));
}
