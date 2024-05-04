/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:34:51 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/02 03:48:04 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "exec.h"

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_tree	*tree;
	t_utils	utils;

	(void)argc;
	(void)argv;
	utils.env_vector = new_vector(10, sizeof(t_env));
	init_env(&utils, envp);
	while (1)
	{
		str = readline("minishell$> ");
		add_history(str);
		tree = parse(str);
		if (!tree)
			continue ;
		utils.root = tree;
		utils.fds_vector = new_vector(10, sizeof(int));
		if (utils.fds_vector == NULL)
		{
			free_tree(&tree);
			close(STDIN_FILENO);
			close(STDOUT_FILENO);
			return (1);
		}
		if (tree != NULL)
		{
			make_all_heredocs(tree);
			if (change_exit_val(-check_id(exec(tree, &utils)), &utils) == 1)
				return (1);
			while (wait(NULL) >= 0)
				;
		}
		del_vector(utils.fds_vector, NULL);
		free_tree(&tree);
	}
}
