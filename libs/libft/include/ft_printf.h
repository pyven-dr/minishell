/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:23 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 18:04:50 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

int		ft_printf(int fd, const	char *format, ...);
int		ft_putchar(char c, t_vector *buffer);
int		ft_putstr(char *s, t_vector *buffer);
int		ft_printf_int(int n, t_vector *buffer);
int		fill_buffer(t_vector *buffer, const char *format, va_list ap);

#endif