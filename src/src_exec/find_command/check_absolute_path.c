/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_absolute_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:53:28 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 00:53:28 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*check_absolute_path(char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/') \
		|| (cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
	}
	return (NULL);
}
