/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sig_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 00:25:17 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/21 00:25:17 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_signal.h"

extern int	g_s;

int	check_sig_pipe(t_utils *utils)
{
	if (g_s == SIGINT)
	{
		change_exit_val(130, utils);
		g_s = 0;
		return (-130);
	}
	if (g_s == SIGQUIT)
	{
		change_exit_val(131, utils);
		g_s = 0;
		return (-131);
	}
	return (0);
}
