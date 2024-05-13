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

int	main(int argc, char **argv, char **envp)
{
	t_utils				utils;

	(void)argc;
	(void)argv;
	utils.env_vector = new_vector(10, sizeof(t_env));
	if (utils.env_vector == NULL)
		return (1);
	init_env(&utils, envp);
	exec_loop(&utils);
}
