/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:41:47 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/11 23:41:47 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parsing.h"

static int	event(void)
{
	return (0);
}

void	init_sig(void)
{
	struct sigaction	sig_a;

	sig_a.sa_flags = 0;
	sigemptyset(&sig_a.sa_mask);
	sig_a.sa_handler = signal_handler;
	sigaction(SIGINT, &sig_a, NULL);
	sig_a.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sig_a, NULL);
	rl_event_hook = event;
}
