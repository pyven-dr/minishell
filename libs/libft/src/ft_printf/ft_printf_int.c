/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:36:09 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 18:02:12 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_lenght(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_putnbr(long n, t_vector *buffer)
{
	char	nb;

	if (n < 0)
	{
		if (add_vector(buffer, "-", NULL) == -1)
			return (-1);
		n = -n;
	}
	nb = 48 + (n % 10);
	if (n / 10 == 0)
	{
		if (add_vector(buffer, &nb, NULL) == -1)
			return (-1);
		return (0);
	}
	if (ft_putnbr(n / 10, buffer) == -1)
		return (-1);
	if (add_vector(buffer, &nb, NULL) == -1)
		return (-1);
	return (0);
}

int	ft_printf_int(int n, t_vector *buffer)
{
	if (ft_putnbr(n, buffer) == -1)
		return (-1);
	return (get_lenght(n));
}
