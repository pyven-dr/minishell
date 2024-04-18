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

int		ft_printf(int fd, const	char *format, ...);
int		ft_putchar(int fd, char c, int *i);
int		ft_putstr(int fd, char *s, int *i);
int		ft_printf_int(int fd, int n, int *i);
int		ft_printf_unsigned(int fd, unsigned int n, int *i);
int		ft_putnbr_hex(int fd, unsigned int nbr, char *base, int *i);
int		ft_print_adress(int fd, unsigned long adress, int *i, char *base);
size_t	ft_strlen(const char *s);

#endif