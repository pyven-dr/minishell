/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:41:03 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/15 19:45:12 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_is_quoted	remove_quote_heredoc(char *s)
{
	t_quote		scope;
	size_t		i;
	t_is_quoted	st;

	scope.s_quote = false;
	scope.d_quote = false;
	st.is_quoted = false;
	st.str = malloc((count_size(s) + 1) * sizeof(char));
	if (!st.str)
		return (free(s), st);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			st.is_quoted = true;
		while ((s[i] == '\'' || s[i] == '"') && !is_quoted_sup(&scope, s[i]))
			s++;
		st.str[i] = s[i];
		if (s[i])
			i++;
	}
	st.str[i] = '\0';
	return (put_quote_back(st.str), st);
}
