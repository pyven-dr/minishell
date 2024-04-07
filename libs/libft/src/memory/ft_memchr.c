/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:18:23 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/14 15:45:57 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*mem;

	i = 0;
	mem = s;
	while (i < n)
	{
		if (mem[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
