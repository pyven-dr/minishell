/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pathmax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 05:11:39 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/01 05:11:39 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*add_slash_pwd(char *pwd)
{
	char	*temp;

	temp = pwd;
	pwd = ft_strjoin(temp, "/");
	free(temp);
	return (pwd);
}

static char	*symplify_path(char *curpath, char *directory)
{
	char	*pwd;
	char 	*pwd_pos;
	char	*temp;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (NULL);
	pwd = add_slash_pwd(pwd);
	if (pwd == NULL)
		return (NULL);
	pwd_pos = ft_strnstr(curpath, pwd, ft_strlen(pwd));
	if (pwd_pos == NULL || pwd_pos != curpath)
	{
		ft_printf(2, "minishell: cd: %s: File name too long\n", directory);
		free(pwd_pos);
		free(pwd);
		return (NULL);
	}
	temp = curpath;
	curpath = ft_strdup(temp + ft_strlen(pwd));
	free(pwd);
	free(temp);
	return (curpath);
}

char	*check_pathmax(char *curpath, char *directory)
{
	if (ft_strlen(curpath) < PATH_MAX)
		return (curpath);
	if (ft_strlen(directory) < PATH_MAX)
	{
		curpath = symplify_path(curpath, directory);
		if (curpath == NULL)
			return (NULL);
		return (curpath);
	}
	free(curpath);
	ft_printf(2, "minishell: cd: %s: File name too long\n", directory);
	return (NULL);
}