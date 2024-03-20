/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:21:55 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/14 18:48:07 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*mem1;
	const unsigned char	*mem2;

	i = 0;
	mem1 = s1;
	mem2 = s2;
	while (i < n)
	{
		if (mem1[i] != mem2[i])
		{
			return ((mem1[i]) - (mem2[i]));
		}
		i++;
	}
	return (0);
}
