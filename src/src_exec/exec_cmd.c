/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:28:24 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/20 00:28:24 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parsing.h"

int	exec_cmd(char **cmd, t_utils *utils)
{
	pid_t	id;
	char	**env;

	id = fork();
	if (id < 0)
	{
		perror("Fork error");
		return (-1);
	}
	if (id == 0)
	{
		env = create_env(utils->env_vector);
		if (env == NULL)
			exit(1);
		close_fds(utils);
		execve(cmd[0], cmd, env);
		perror("Execve error");
		free_tab(cmd);
		if (errno == EACCES)
			exit(126);
		exit(1);
	}
	free_tab(cmd);
	return (id);
}
