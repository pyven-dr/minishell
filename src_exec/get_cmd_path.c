/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:52:17 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 00:52:17 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*get_cmd_path(char *command)
{
	char	*path;
	char	**splitted_path;
	char	*command_path;

	path = getenv("PATH");
	if (path == NULL)
	{
		command_path = check_absolute_path(command);
		free(command);
		return (command_path);
	}
	splitted_path = ft_split(path, ':');
	if (splitted_path == NULL)
		return (free(command), NULL);
	if (command != NULL)
		command_path = check_absolute_path(command);
	if (command_path == NULL && command != NULL)
		command_path = find_command(splitted_path, command);
	else if (command_path == NULL)
		ft_putstr_fd("'': command not found\n", STDERR_FILENO);
	free(command);
	free_cmd(splitted_path);
	free(splitted_path);
	return (command_path);
}
