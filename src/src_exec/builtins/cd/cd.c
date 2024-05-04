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

static void	free_dir(char *directory, char **args)
{
	if (nb_args(args) == 1)
		free(directory);
}

int	print_curpath(int print_path, char *curpath)
{
	if (print_path == 1)
	{
		if (ft_putendl_fd(curpath, 1) == -1)
		{
			free(curpath);
			return (1);
		}
	}
	return (0);
}

int	cd(char **args, t_utils *utils)
{
	char	*directory;
	char	*curpath;
	int		print_path;

	print_path = 0;
	directory = check_args_cd(args, utils);
	if (directory == NULL)
		return (-1);
	curpath = get_curpath(directory, utils, &print_path);
	if (curpath == NULL)
	{
		free_dir(directory, args);
		return (-1);
	}
	if (check_curpath(curpath, directory) == 1)
		return (free_dir(directory, args), -1);
	if (change_dir(curpath, utils) == 1)
	{
		perror("minishell: cd");
		return (free_dir(directory, args), -1);
	}
	if (print_curpath(print_path, curpath) == 1)
		return (free_dir(directory, args), -1);
	free(curpath);
	return (free_dir(directory, args), 0);
}
