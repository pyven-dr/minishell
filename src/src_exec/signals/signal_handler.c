/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 02:23:08 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/17 02:23:08 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parsing.h"

void	signal_handler(int signal)
{
	if (signal != 0)
	{
		g_s = signal;
		rl_replace_line("", 0);
		rl_done = 1;
	}
}
