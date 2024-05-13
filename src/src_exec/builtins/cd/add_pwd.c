/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:13:21 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/01 06:13:21 by pyven-dr         ###   ########.fr       */
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
	{
		perror(ERR_PDW_CD);
		return (NULL);
	}
	new_curpath = ft_strjoin(pwd, temp_curpath);
	free(pwd);
	free(temp_curpath);
	if (new_curpath == NULL)
		return (NULL);
	return (new_curpath);
}
