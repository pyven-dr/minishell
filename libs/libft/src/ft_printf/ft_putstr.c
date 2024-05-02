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

int	ft_putstr(char *s, t_vector *buffer)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (add_vector(buffer, &s[i], NULL) == -1)
			return (-1);
		i++;
	}
	return ((int)ft_strlen(s));
}
