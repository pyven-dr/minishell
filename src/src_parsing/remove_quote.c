/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:17:22 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/02 02:16:55 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:17:22 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/25 18:04:31 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	count_size(char	*s)
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

	head = s;
	scope.s_quote = false;
	scope.d_quote = false;
	str = malloc((count_size(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	s = head;
	i = 0;
	while (s[i])
	{
		while ((s[i] == '\'' || s[i] == '"') && !is_quoted_sup(&scope, s[i]))
			s++;
		str[i] = s[i];
		if (s[i])
			i++;
	}
	free (s);
	str[i] = '\0';
	return (str);
}
