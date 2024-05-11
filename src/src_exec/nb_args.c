/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:03:10 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/08 20:03:10 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	nb_args(char **args)
{
	int	nb_args;

	nb_args = 0;

	if (args == NULL)
		return (0);
	while (args[nb_args] != NULL)
		nb_args++;
	return (nb_args);
}
