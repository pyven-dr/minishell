/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:17:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/12 18:21:43 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	i = ft_strlen(s);
	if (start >= i)
		return (NULL);
	else if ((i - start) >= len)
		res = malloc(sizeof(char) * (len + 1));
	else
		res = malloc(sizeof(char) * ((i - start) + 1));
	i = 0;
	if (!res)
		return (NULL);
	while (i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
