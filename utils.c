/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:12:08 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/23 04:58:28 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*(unsigned char *)s1 && *(unsigned char *)s2 && --n > 0)
	{
		if (*(unsigned char *)s1 - *(unsigned char *)s2 != 0)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	long	i;
	long	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	str = malloc((i + j + 2) * sizeof(char));
	if (!str)
		return (free(s1), free(s2), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (free(s1), free(s2), str);
}

int	ft_strncmp_improved(const char *s1, char **s2, size_t n)
{
	t_quote	scope;

	scope.d_quote = false;
	scope.s_quote = false;
	if (!n)
		return (0);
	while (*(unsigned char *)s1 && *(unsigned char *)*s2 && --n > 0)
	{
		while ((*s1 == '"' || *s1 == '\'') && !is_quoted_sup(&scope, *s1))
			s1++;
		if (!*s1)
			return (0);
		if (*(unsigned char *)s1 - *(unsigned char *)*s2 != 0)
			return (*(unsigned char *)s1 - *(unsigned char *)*s2);
		s1++;
		(*s2)++;
	}
	if (n)
		return (0);
	if (*(unsigned char *)s1 - *(unsigned char *)*s2)
		return (*(unsigned char *)s1 - *(unsigned char *)*s2);
	(*s2)++;
	return (0);
}

bool	there_is_a_wildcard(char *s)
{
	t_quote	scope;

	scope.s_quote = false;
	scope.d_quote = false;
	while (*s)
	{
		if (!is_quoted(&scope, *s) && *s == '*')
			return (true);
		s++;
	}
	return (false);
}
