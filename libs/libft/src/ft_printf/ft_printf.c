/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:47:02 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 18:07:17 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(int fd, const	char *format, ...)
{
	t_vector	*buffer;
	va_list		ap;
	int			lenght;

	buffer = new_vector(1, sizeof(char));
	if (buffer == NULL)
		return (-1);
	va_start(ap, format);
	lenght = fill_buffer(buffer, format, ap);
	if (lenght == -1)
		return (-1);
	va_end(ap);
	if (write(fd, (char *)buffer->elements, lenght) == -1)
		return (-1);
	del_vector(buffer, NULL);
	return (lenght);
}
