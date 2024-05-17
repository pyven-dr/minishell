/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:28:24 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/16 18:27:14 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parsing.h"

int	exec_cmd(char **cmd, t_utils *utils, t_tree *root)
{
	pid_t	id;
	char	**env;

	id = fork();
	if (id < 0)
		return (perror("minishell: Fork error"), -1);
	if (id == 0)
	{
		sig_exec();
		free_tree(&root);
		env = create_env(utils->env_vector);
		if (env == NULL || close_fds(utils) == 1)
		{
			free_utils(NULL, utils);
			exit(1);
		}
		free_utils(NULL, utils);
		execve(cmd[0], cmd, env);
		perror("minishell: Execve error");
		free_tab(cmd);
		if (errno == EACCES)
			exit(126);
		exit(1);
	}
	return (free_tab(cmd), id);
}
