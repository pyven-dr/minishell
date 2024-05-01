/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:50:41 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/27 17:16:33 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	check_first_component(char *directory)
{
	int	i;

	i = 0;
	while (directory[i] == '.')
		i++;
	if (i == 2 || i == 1)
		return (0);
	return (1);
}

static void	free_dir(char *directory, char **args)
{
	if (nb_args(args) == 1)
		free(directory);
}

int	cd(char **args, t_utils *utils)
{
	char	*directory;
	char	*curpath;

	directory = check_args_cd(args, utils);
	if (directory == NULL)
		return (1);
	if (directory[0] == '/' || check_first_component(directory) == 0)
		curpath = ft_strdup(directory);
	else
		curpath = check_cdpath(utils, directory);
	if (curpath == NULL)
		return (free_dir(directory, args), 1);
	curpath = add_pwd(curpath);
	if (curpath == NULL)
		return (free_dir(directory, args), 1);
	curpath = canonize(curpath, directory);
	if (curpath == NULL)
		return (free_dir(directory, args), 1);
	curpath = check_pathmax(curpath, directory);
	if (curpath == NULL)
		return (free_dir(directory, args), 1);
	if (change_dir(curpath, utils) == 1)
		return (free_dir(directory, args), 1);
	free(curpath);
	return (free_dir(directory, args), 0);
}
