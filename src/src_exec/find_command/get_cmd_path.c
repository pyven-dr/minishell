/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:52:17 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/25 15:45:14 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*get_path(t_vector *env_vector)
{
	char	*path;
	int		path_index;
	t_env	*path_env;

	path_index = ft_getenv("PATH", env_vector);
	if (path_index == -1)
		return (NULL);
	path_env = get_elem_vector(env_vector, path_index);
	path = path_env->value;
	return (path);
}

char	*get_cmd_path(char *command, t_vector *env_vector)
{
	char	*path;
	char	**splitted_path;
	char	*command_path;

	command_path = NULL;
	path = get_path(env_vector);
	if (path == NULL)
	{
		ft_printf(2, "minishell: %s: No such file or directory\n", command);
		command_path = check_absolute_path(command);
		return (free(command), command_path);
	}
	splitted_path = ft_split(path, ':');
	if (splitted_path == NULL)
		return (free(command), NULL);
	if (command != NULL)
		command_path = check_absolute_path(command);
	if (command_path == NULL && command != NULL)
		command_path = find_command(splitted_path, command);
	else if (command_path == NULL)
		ft_putstr_fd("'': command not found\n", 2);
	free(command);
	free_cmd(splitted_path);
	free(splitted_path);
	return (command_path);
}
