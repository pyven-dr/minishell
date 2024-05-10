/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:00:20 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/23 00:00:20 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	check_id(int id, t_utils *utils)
{
	int	status;

	if (id < 0)
		return (id);
	else if (id > 0)
	{
		if (waitpid(id, &status, 0) == -1)
		{
			change_exit_val(1, utils);
			return (-1);
		}
		if (WEXITSTATUS(status) != 0)
		{
			if (change_exit_val(WEXITSTATUS(status), utils) == 1)
				return (-1);
			return (WEXITSTATUS(status) * -1);
		}
	}
	if (change_exit_val(0, utils) == 1)
		return (-1);
	return (0);
}
