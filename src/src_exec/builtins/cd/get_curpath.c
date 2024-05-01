/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:35:49 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/02 00:35:49 by pyven-dr         ###   ########.fr       */
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

char	*get_oldpwd(t_utils *utils, int *print_path)
{
	int		index;
	t_env	*oldpwd;

	index = ft_getenv("OLDPWD", utils->env_vector);
	if (index == -1)
	{
		ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
		return (NULL);
	}
	oldpwd = get_elem_vector(utils->env_vector, index);
	*print_path = 1;
	return (ft_strdup(oldpwd->value));
}

char	*get_curpath(char *directory, t_utils *utils, int *print_path)
{
	char	*curpath;

	if (ft_strcmp(directory, "-") == 0)
		curpath = get_oldpwd(utils, print_path);
	else if (directory[0] == '/' || check_first_component(directory) == 0)
		curpath = ft_strdup(directory);
	else
		curpath = check_cdpath(utils, directory, print_path);
	if (curpath == NULL)
		return (NULL);
	curpath = add_pwd(curpath);
	if (curpath == NULL)
		return (NULL);
	curpath = canonize(curpath, directory);
	if (curpath == NULL)
		return (NULL);
	curpath = check_pathmax(curpath, directory);
	if (curpath == NULL)
		return (NULL);
	return (curpath);
}
