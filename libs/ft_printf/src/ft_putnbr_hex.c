/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:24:06 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 18:07:47 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(int fd, unsigned int nbr, char *base, int *i)
{
	if (nbr / 16 == 0)
	{
		if (write(fd, &base[nbr % 16], 1) == -1)
			return (-1);
		*i += 1;
		return (0);
	}
	if (ft_putnbr_hex(fd, nbr / 16, base, &*i) == -1 || \
		write(fd, &base[nbr % 16], 1) == -1)
		return (-1);
	*i += 1;
	return (0);
}
