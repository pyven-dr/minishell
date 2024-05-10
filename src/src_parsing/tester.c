/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:34:51 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/07 20:37:03 by sabitbol         ###   ########.fr       */
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
	if (utils.env_vector == NULL)
		return (1);
	init_env(&utils, envp);
	while (1)
	{
		str = readline("minishell$> ");
		add_history(str);
		tree = parse(str);
		if (!tree)
		{
			change_exit_val(2, &utils);
			continue ;
		}
		utils.root = tree;
		utils.fds_vector = new_vector(10, sizeof(int));
		if (utils.fds_vector == NULL)
			change_exit_val(1, &utils);
		if (tree != NULL && utils.fds_vector != NULL)
		{
			make_all_heredocs(tree);
			check_id(exec(tree, &utils), &utils);
			//while (wait(NULL) >= 0)
			//	;
		}
		del_vector(utils.fds_vector, NULL);
		free_tree(&tree);
	}
}
