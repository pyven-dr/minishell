/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:55:53 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/14 14:57:55 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*mem_dest;
	const unsigned char	*mem_src;

	mem_dest = dest;
	mem_src = src;
	if ((!dest && !src) || !n)
		return (dest);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			mem_dest[i - 1] = mem_src[i - 1];
			i--;
		}
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		mem_dest[i] = mem_src[i];
		i++;
	}
	return (dest);
}
