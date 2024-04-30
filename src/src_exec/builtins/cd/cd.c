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

char	*add_pwd(char *curpath)
{
	char	*pwd;
	char	*new_curpath;

	if (curpath[0] == '/')
		return (curpath);
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (NULL);
	new_curpath = ft_strjoin(pwd, curpath);
	free(pwd);
	free(curpath);
	if (new_curpath == NULL)
		return (NULL);
	return (new_curpath);
}

int	check_first_component(char *directory)
{
	int	i;

	i = 0;
	while (directory[i] == '.')
		i++;
	if (i == 2 || i == 1)
		return (0);
	return (1);
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
		return (1);
	curpath = add_pwd(curpath);
	printf("curpath = %s\n", curpath);
	free(curpath);
	return (0);
}
