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
	int	length;

	length = 0;
	if (arg == 'c')
		length = ft_putchar((char)va_arg(ap, int), buffer);
	else if (arg == 's')
		length = ft_putstr(va_arg(ap, char *), buffer);
	else if (arg == 'd' || arg == 'i')
		length = ft_printf_int(va_arg(ap, int), buffer);
	if (length == -1)
		buffer->capacity = 0;
	return (length);
}

int	fill_buffer(t_vector *buffer, const char *format, va_list ap)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			length += conversion(buffer, format[i + 1], ap);
			i++;
		}
		else
			length += ft_putchar(format[i], buffer);
		if (buffer->capacity == 0)
			return (del_vector(buffer, NULL), -1);
		i++;
	}
	return (length);
}
