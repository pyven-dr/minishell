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

static int	chech_n(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
	{
		i++;
		while (arg[i] != '\0')
		{
			if (arg[i] != 'n')
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

int	echo(char **args)
{
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	while (chech_n(args[i]) == 0)
	{
		nl = 0;
		i++;
	}
	while (args[i] != NULL)
	{
		if (write(1, args[i], ft_strlen(args[i])) == -1)
			return (-1);
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
