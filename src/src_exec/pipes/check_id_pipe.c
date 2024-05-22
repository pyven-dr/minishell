/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:41:25 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/20 23:41:25 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_pipe.h"
#include "exec_signal.h"
#include <sys/wait.h>

static int	check_status(int status, t_utils *utils)
{
	if (WIFSIGNALED(status) == true)
		return (check_sig_pipe(utils));
	else if (WEXITSTATUS(status) != 0)
	{
		if (change_exit_val(WEXITSTATUS(status), utils) == 1)
			return (-1);
		return (WEXITSTATUS(status) * -1);
	}
	return (0);
}

int	check_id_pipe(int id, t_utils *utils)
{
	int	status;

	if (id < 0)
		return (id);
	else if (id > 0)
	{
		sig_end_exec();
		if (waitpid(id, &status, 0) == -1)
		{
			change_exit_val(1, utils);
			return (-1);
		}
		return (check_status(status, utils));
	}
	if (change_exit_val(0, utils) == 1)
		return (-1);
	return (0);
}
