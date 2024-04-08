/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:35:55 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/14 19:22:35 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (ft_putstr_fd(s, fd) == 1)
		return (1);
	if (ft_putchar_fd('\n', fd) == 1)
		return (1);
	return (0);
}
