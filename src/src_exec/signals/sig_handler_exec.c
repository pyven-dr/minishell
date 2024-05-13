/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:34:17 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/12 17:34:17 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parsing.h"

static void	signal_handler_command(int signal)
{
	g_s = signal;
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_done = 1;
	}
	else if (signal == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_done = 1;
	}
}

void	sig_exec(void)
{
	struct sigaction	sig_a;

	sig_a.sa_flags = 0;
	sigemptyset(&sig_a.sa_mask);
	sig_a.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sig_a, NULL);
	sigaction(SIGQUIT, &sig_a, NULL);
}

void	sig_end_exec(void)
{
	struct sigaction	sig_a;

	sig_a.sa_flags = SA_RESTART;
	sigemptyset(&sig_a.sa_mask);
	sig_a.sa_handler = signal_handler_command;
	sigaction(SIGINT, &sig_a, NULL);
	sigaction(SIGQUIT, &sig_a, NULL);
}
