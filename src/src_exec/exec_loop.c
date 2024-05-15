/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:51:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/15 18:55:52 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parsing.h"

static void	exec_line(char *line, t_utils *utils)
{
	t_tree	*tree;

	tree = parse(line);
	if (tree == NULL)
	{
		change_exit_val(2, utils);
		return ;
	}
	if (make_all_heredocs(tree, utils->env_vector) == 0)
		check_id(exec(tree, utils), utils);
	del_all_heredocs(tree);
	free_tree(&tree);
}

void	exec_loop(t_utils *utils)
{
	char	*str;

	while (1)
	{
		init_sig();
		utils->fds_vector = new_vector(10, sizeof(int));
		if (utils->fds_vector == NULL)
			change_exit_val(1, utils);
		str = readline("minishell$> ");
		if (str == NULL)
			exit_builtin(NULL, utils);
		add_history(str);
		if (utils->fds_vector != NULL)
		{
			exec_line(str, utils);
			del_vector(utils->fds_vector, NULL);
		}
		check_sig(utils);
	}
}