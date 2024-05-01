/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:14:38 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/01 06:14:38 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	change_env(char *pwd, char *oldpwd, t_utils *utils)
{
	char	*temp;
	char	*export_arg[4];
	int		export_return;

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
