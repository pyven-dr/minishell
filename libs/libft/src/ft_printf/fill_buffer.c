/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 05:32:04 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/02 05:32:04 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(t_vector *buffer, char arg, va_list ap)
{
	int	lenght;

	lenght = 0;
	if (arg == 'c')
		lenght = ft_putchar((char)va_arg(ap, int), buffer);
	else if (arg == 's')
		lenght = ft_putstr(va_arg(ap, char *), buffer);
	else if (arg == 'd' || arg == 'i')
		lenght = ft_printf_int(va_arg(ap, int), buffer);
	if (lenght == -1)
		buffer->capacity = 0;
	return (lenght);
}

int	fill_buffer(t_vector *buffer, const char *format, va_list ap)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			lenght += conversion(buffer, format[i + 1], ap);
			i++;
		}
		else
			lenght += ft_putchar(format[i], buffer);
		if (buffer->capacity == 0)
			return (del_vector(buffer, NULL), -1);
		i++;
	}
	return (lenght);
}
