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

int	check_id(int id)
{
	int	status;

	status = 0;
	if (id < 0)
		return (id);
	else if (id > 0)
	{
		waitpid(id, &status, 0);
		if (WEXITSTATUS(status) != 0)
			return (status);
	}
	return (0);
}