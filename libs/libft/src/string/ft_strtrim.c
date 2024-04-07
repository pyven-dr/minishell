/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:54:14 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/10 14:15:51 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*fill_res(char const *s1, char *res, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	if (!res)
		return (NULL);
	while (start < end)
	{
		res[i] = s1[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (is_set(set, s1[start]))
		start++;
	while (is_set(set, s1[end - 1]))
		end--;
	if (end < start)
	{
		res = malloc(1);
		*res = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (end - start + 1));
	return (fill_res(s1, res, start, end));
}
