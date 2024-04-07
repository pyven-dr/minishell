/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:15:52 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/09 18:49:53 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	unsigned char	*j;
	size_t			i;
	size_t			m;

	i = 0;
	m = nmemb * size;
	if (m == 0)
	{
		res = malloc(0);
		return (res);
	}
	if ((m / size != nmemb))
		return (NULL);
	res = malloc(m);
	if (!res)
		return (NULL);
	j = res;
	while (i < m)
	{
		j[i] = 0;
		i++;
	}
	return (j);
}
