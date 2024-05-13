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

static int	add_to_env(char	*pwd, t_utils *utils)
{
	char	*export_arg[3];
	int		ret_val;

	export_arg[0] = "export";
	export_arg[1] = pwd;
	export_arg[2] = NULL;
	ret_val = export(export_arg, utils);
	free(pwd);
	return (ret_val);
}

int	change_env(char *pwd, char *oldpwd, t_utils *utils)
{
	char	*temp;

	if (pwd != NULL)
	{
		temp = pwd;
		pwd = ft_strjoin("PWD=", temp);
		free(temp);
		if (pwd == NULL)
			return (1);
		if (add_to_env(pwd, utils) == 1)
			return (1);
	}
	if (oldpwd != NULL)
	{
		temp = oldpwd;
		oldpwd = ft_strjoin("OLDPWD=", temp);
		free(temp);
		if (oldpwd == NULL)
			return (1);
		if (add_to_env(oldpwd, utils) == 1)
			return (1);
	}
	return (0);
}
