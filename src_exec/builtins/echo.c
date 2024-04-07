/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 04:27:53 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/07 04:27:53 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	echo(char **args)
{
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	while (args[i] != NULL)
	{
		if (ft_strcmp(args[i], "-n") == 0)
			nl = 0;
		else
		{
			if (write(1, args[i], ft_strlen(args[i])) == -1)
				return (-1);
		}
		if (args[i + 1] != NULL)
			if (write(1, " ", 1) == -1)
				return (-1);
		i++;
	}
	if (nl == 1)
		if (write(1, "\n", 1) == -1)
			return (-1);
	return (0);
}
