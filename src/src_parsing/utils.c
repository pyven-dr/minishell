/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:12:08 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/30 22:59:19 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void	free_tab(void *content)
{
	size_t	i;
	char	**tab;

	tab = content;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
