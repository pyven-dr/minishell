/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:58:22 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/01 02:58:22 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	check_file(char **components, int last, int nb_components, char *directory)
{
	char		*path;
	struct stat	file;

	path = join_path(components, last, nb_components);
	if (path == NULL)
		return (1);
	if (stat(path, &file) == -1)
	{
		free(path);
		ft_printf(2, "minishell: cd: %s: No such file or directory\n", \
					directory);
		return (1);
	}
	if (S_ISDIR(file.st_mode) == 0)
	{
		free(path);
		ft_printf(2, "minishell: cd: %s: Not a directory\n", directory);
		return (1);
	}
	free(path);
	return (0);
}

int	check_curpath(char *curpath, char *directory)
{
	struct stat	file;

	if (stat(curpath, &file) == -1)
	{
		if (ft_strcmp(directory, "-") == 0)
		{
			ft_printf(2, "minishell: cd: %s: No such file or directory\n", \
					curpath);
		}
		else
		{
			ft_printf(2, "minishell: cd: %s: No such file or directory\n", \
					directory);
		}
		free(curpath);
		return (1);
	}
	if (S_ISDIR(file.st_mode) == 0)
	{
		free(curpath);
		ft_printf(2, "minishell: cd: %s: Not a directory\n", directory);
		return (1);
	}
	return (0);
}
