/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:34:51 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/10 21:27:48 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "exec.h"

int	g_s = 0;

int	check_sig(char *str, t_utils *utils)
{
	if (str == NULL)
		exit_builtin(NULL, utils);
	if (g_s == 1)
	{
		change_exit_val(130, utils);
		g_s = 0;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char				*str;
	t_tree				*tree;
	t_utils				utils;

	(void)argc;
	(void)argv;
	utils.env_vector = new_vector(10, sizeof(t_env));
	if (utils.env_vector == NULL)
		return (1);
	init_env(&utils, envp);
	init_sig();
	while (1)
	{
		utils.fds_vector = new_vector(10, sizeof(int));
		if (utils.fds_vector == NULL)
			change_exit_val(1, &utils);
		str = readline("minishell$> ");
		check_sig(str, &utils);
		add_history(str);
		tree = parse(str);
		if (!tree)
			change_exit_val(2, &utils);
		utils.root = tree;
		if (tree != NULL && utils.fds_vector != NULL)
		{
			make_all_heredocs(tree);
			check_id(exec(tree, &utils), &utils);
		}
		/*sigaction(SIGQUIT, &s, NULL);
		s.sa_handler = NULL;
		sigaction(SIGINT, &s, NULL);*/
		del_vector(utils.fds_vector, NULL);
		free_tree(&tree);
	}
}
