/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:50:13 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 00:50:13 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*find_command(char **path, char *command)
{
	size_t	i;
	char	*command_path;
	char	*temp;

	i = 0;
	temp = ft_strjoin("/", command);
	if (temp == NULL)
		return (NULL);
	while (path[i])
	{
		command_path = ft_strjoin(path[i], temp);
		if (command_path == NULL)
			return (free(temp), NULL);
		if (access(command_path, F_OK) == 0)
			return (free(temp), command_path);
		free(command_path);
		i++;
	}
	free(temp);
	if (ft_printf(2, "minishell: %s: command not found\n", command) == -1)
		return (NULL);
	return (NULL);
}
