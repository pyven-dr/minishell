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
	char	*temp_curpath;

	if (curpath[0] == '/')
		return (curpath);
	temp_curpath = ft_strjoin("/", curpath);
	free(curpath);
	if (temp_curpath == NULL)
		return (NULL);
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (NULL);
	new_curpath = ft_strjoin(pwd, temp_curpath);
	free(pwd);
	free(temp_curpath);
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

int	change_env(char *pwd, char *oldpwd, t_utils *utils)
{
	char	*temp;
	char 	*export_arg[4];
	int 	export_return;

	temp = pwd;
	pwd = ft_strjoin("PWD=", temp);
	free(temp);
	if (pwd == NULL)
		return (1);
	temp = oldpwd;
	oldpwd = ft_strjoin("OLDPWD=", temp);
	free(temp);
	if (oldpwd == NULL)
		return (free(pwd), 1);
	export_arg[0] = "export";
	export_arg[1] = pwd;
	export_arg[2] = oldpwd;
	export_arg[3] = NULL;
	export_return = export(export_arg, utils);
	free(pwd);
	free(oldpwd);
	return (export_return);
}

int	change_dir(char *curpath, t_utils *utils)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = getcwd(NULL, 0);
	if (oldpwd == NULL)
		return (1);
	if (chdir(curpath) == -1)
	{
		free(oldpwd);
		free(curpath);
		return (1);
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (free(oldpwd), 1);
	return (change_env(pwd, oldpwd, utils));
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
	if (curpath == NULL)
		return (1);
	curpath = canonize(curpath, directory);
	if (curpath == NULL)
		return (1);
	if (change_dir(curpath, utils) == 1)
		return (1);
	printf("curpath = %s\n", curpath);
	free(directory);
	free(curpath);
	return (0);
}
