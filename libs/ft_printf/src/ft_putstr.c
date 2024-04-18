/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:12:35 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 17:58:46 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(int fd, char *s, int *i)
{
	size_t	len;

	if (s == NULL)
	{
		if (write(fd, "(null)", 6) == -1)
			return (-1);
		*i += 6;
		return (0);
	}
	len = ft_strlen(s);
	if (write(fd, s, len) == -1)
		return (-1);
	*i += len;
	return (0);
}
