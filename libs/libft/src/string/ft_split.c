/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:14:03 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/15 17:40:37 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_free(char **res, size_t j)
{
	size_t	i;

	i = 0;
	while (j >= i)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	count_words(const char *s, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			i++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static	void	fill(const char *s, size_t	size, char	*dest)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}

static int	cut(char	const *s, char c, char **res, size_t i)
{
	size_t	j;
	size_t	k;

	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			k = i;
			i++;
			while (s[i] && s[i] != c)
				i++;
			res[j] = malloc(sizeof(char) * (i - k + 1));
			if (!res[j])
			{
				ft_free(res, j);
				return (0);
			}
			fill(&s[k], i - k, res[j]);
			j++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;

	count = count_words(s, c);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	if (cut(s, c, res, 0) == 0)
		return (NULL);
	res[count] = NULL;
	return (res);
}
