/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:30:20 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 18:02:06 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_i(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_putunnbr(int fd, unsigned int n)
{
	char	nb;

	nb = 48 + (n % 10);
	if (n / 10 == 0)
	{
		if (write (fd, &nb, 1) == -1)
			return (-1);
		return (0);
	}
	if (ft_putunnbr(fd, n / 10) == -1)
		return (-1);
	if (write(fd, &nb, 1) == -1)
		return (-1);
	return (0);
}

int	ft_printf_unsigned(int fd, unsigned int n, int *i)
{
	*i += add_i(n);
	return (ft_putunnbr(fd, n));
}
