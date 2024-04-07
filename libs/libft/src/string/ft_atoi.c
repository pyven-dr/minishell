/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:47:24 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/14 00:51:04 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	return_value(int min)
{
	if (min == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

long int	ft_atol(const char *nptr)
{
	size_t		i;
	long int	res;
	int			min;

	i = 0;
	res = 0;
	min = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			min = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - 48);
		if (res < 0)
			return (return_value(min));
		i++;
	}
	return (res * min);
}

int	ft_atoi(const char *nptr)
{
	return (ft_atol(nptr));
}
