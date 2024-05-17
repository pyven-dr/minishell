/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sig_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:20:14 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/17 21:20:14 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	print_sig_cmd(void)
{
	if (g_s == SIGINT)
	{
		if (ft_putchar_fd('\n', STDERR_FILENO) == -1)
			return (1);
	}
	else if (g_s == SIGQUIT)
	{
		if (ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO) == -1)
			return (1);
	}
	return (0);
}
