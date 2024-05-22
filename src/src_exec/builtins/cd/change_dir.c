/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:15:42 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/01 06:15:42 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_error.h"
#include "exec_builtins.h"

int	change_dir(char *curpath, t_utils *utils)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = getcwd(NULL, 0);
	if (oldpwd == NULL)
		perror(ERR_PDW_CD);
	if (chdir(curpath) == -1)
	{
		if (oldpwd != NULL)
			free(oldpwd);
		free(curpath);
		return (1);
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		perror(ERR_PDW_CD);
	return (change_env(pwd, oldpwd, utils));
}
