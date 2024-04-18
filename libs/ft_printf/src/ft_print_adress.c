/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:25:15 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 18:02:20 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_adress(int fd, unsigned long nb, int *i, char *base)
{
	if (nb / 16 == 0)
	{
		if (write(fd, &base[nb % 16], 1) == -1)
			return (-1);
		*i += 1;
		return (0);
	}
	if (ft_put_adress(fd, nb / 16, &*i, base) == -1 || \
		write(fd, &base[nb % 16], 1) == -1)
		return (-1);
	*i += 1;
	return (0);
}

int	ft_print_adress(int fd, unsigned long nb, int *i, char *base)
{
	if (nb == 0)
	{
		if (write(fd, "(nil)", 5) == -1)
			return (0);
		*i += 5;
		return (1);
	}
	if (write(fd, "0x", 2) == -1)
		return (-1);
	*i += 2;
	ft_put_adress(fd, nb, &*i, base);
	return (0);
}
