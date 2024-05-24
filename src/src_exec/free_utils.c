/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:14:50 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/24 18:14:50 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	free_utils(char **args, t_utils *utils)
{
	if (args != NULL)
		free_tab(args);
	del_vector(utils->env_vector, free_env_line);
	del_vector(utils->fds_vector, NULL);
}
