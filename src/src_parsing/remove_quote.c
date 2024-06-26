/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:17:22 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/15 19:42:46 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	count_size(char	*s)
{
	size_t	i;
	t_quote	scope;

	scope.s_quote = false;
	scope.d_quote = false;
	i = 0;
	while (s[i])
	{
		while ((s[i] == '\'' || s[i] == '"') && !is_quoted_sup(&scope, s[i]))
			s++;
		if (s[i])
			i++;
	}
	return (i);
}

char	*remove_quote(char *s)
{
	t_quote	scope;
	size_t	i;
	char	*str;
	char	*head;

	scope.s_quote = false;
	scope.d_quote = false;
	str = malloc((count_size(s) + 1) * sizeof(char));
	if (!str)
		return (free(s), NULL);
	i = 0;
	head = s;
	while (s[i])
	{
		while ((s[i] == '\'' || s[i] == '"') && !is_quoted_sup(&scope, s[i]))
			s++;
		str[i] = s[i];
		if (s[i])
			i++;
	}
	s = head;
	free (s);
	str[i] = '\0';
	return (put_quote_back(str));
}

char	**remove_quote_from_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		tab[i] = remove_quote(tab[i]);
		if (!tab[i])
		{
			while (i-- > 0)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
		i++;
	}
	return (tab);
}

char	*replace_quote(char *s)
{
	char	*head;

	head = s;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '"')
			*s = -2;
		else if (*s == '\'')
			*s = -1;
		s++;
	}
	return (head);
}

char	*put_quote_back(char *s)
{
	char	*head;

	head = s;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == -2)
			*s = '"';
		else if (*s == -1)
			*s = '\'';
		s++;
	}
	return (head);
}
