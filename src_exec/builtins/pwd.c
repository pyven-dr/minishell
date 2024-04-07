/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 09:57:22 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/07 09:57:22 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (-1);
	if (write(1, cwd, ft_strlen(cwd)) == -1)
	{
		free(cwd);
		return (-1);
	}
	free(cwd);
	if (write(1, "\n", 1) == -1)
		return (-1);
	return (0);
}