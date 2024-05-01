/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:59:22 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/20 00:59:22 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	free_cmd(char **cmd)
{
	size_t	i;

	i = 0;
	if (cmd == NULL)
		return ;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
}