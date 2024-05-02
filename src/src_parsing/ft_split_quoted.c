/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quoted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:40:08 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/02 02:16:23 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	count_words(char *s);
static char		*do_word(char *s);
static void		free_all(char **tab);

char	**ft_split_quoted(char *s)
{
	t_quote	scope;
	char	**tab;
	size_t	i;

	scope.d_quote = false;
	scope.s_quote = false;
	tab = malloc((count_words(s) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_whitespace(*s))
			s++;
		if (*s)
		{
			tab[i] = do_word(s);
			if (!tab[i++])
				return (free_all(tab), free(tab), NULL);
		}
		while (*s && (is_quoted(&scope, *s) || !is_whitespace(*s)))
			s++;
	}
	tab[i] = NULL;
	return (tab);
}

static size_t	count_words(char *s)
{
	size_t	count;
	t_quote	scope;

	scope.d_quote = false;
	scope.s_quote = false;
	count = 0;
	while (*s)
	{
		while (*s && is_whitespace(*s))
			s++;
		if (*s)
			count++;
		while (*s && (is_quoted(&scope, *s) || !is_whitespace(*s)))
			s++;
	}
	return (count);
}

static char	*do_word(char *s)
{
	t_quote	scope;
	size_t	i;
	char	*str;

	scope.d_quote = false;
	scope.s_quote = false;
	i = 0;
	while (s[i] && (is_quoted(&scope, s[i]) || !is_whitespace(s[i])))
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && (is_quoted(&scope, s[i]) || !is_whitespace(s[i])))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	free_all(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}
