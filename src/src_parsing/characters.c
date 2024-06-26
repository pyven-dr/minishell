/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:26:56 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/25 16:47:46 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_whitespace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (true);
	return (false);
}

t_operand	is_operand(char **line)
{
	if (**line == '&' && *((*line) + 1) == '&')
		return ((*line) += 2, AND);
	else if (**line == '|' && *((*line) + 1) == '|')
		return ((*line) += 2, OR);
	else if (**line == '|')
		return ((*line)++, PIPE);
	else if (**line == '<' && *((*line) + 1) == '<')
		return ((*line) += 2, DOUBLE_IN);
	else if (**line == '<')
		return ((*line)++, SIMPLE_IN);
	else if (**line == '>' && *((*line) + 1) == '>')
		return ((*line) += 2, DOUBLE_OUT);
	else if (**line == '>')
		return ((*line)++, SIMPLE_OUT);
	else
		return (CMD);
}

bool	is_special(char c)
{
	if (c == '&' || c == '|' || c == '<' || c == '>' \
	|| c == '(' || c == ')' || c == '\'' || c == '"')
		return (true);
	return (false);
}

bool	is_quoted(t_quote *scope, char c)
{
	if (c == '"')
	{
		if (scope->d_quote == false && scope->s_quote == false)
			scope->d_quote = true;
		else if (scope->d_quote == true)
			scope->d_quote = false;
		return (true);
	}
	if (c == '\'')
	{
		if (scope->s_quote == false && scope->d_quote == false)
			scope->s_quote = true;
		else if (scope->s_quote == true)
			scope->s_quote = false;
		return (true);
	}
	if (scope->d_quote == true || scope->s_quote == true)
		return (true);
	else
		return (false);
}

bool	is_quoted_sup(t_quote *scope, char c)
{
	if (c == '"')
	{
		if (scope->d_quote == false && scope->s_quote == false)
			return (scope->d_quote = true, false);
		else if (scope->d_quote == true)
			return (scope->d_quote = false, false);
		else
			return (true);
	}
	if (c == '\'')
	{
		if (scope->s_quote == false && scope->d_quote == false)
			return (scope->s_quote = true, false);
		else if (scope->s_quote == true)
			return (scope->s_quote = false, false);
		else
			return (true);
	}
	if (scope->d_quote == true || scope->s_quote == true)
		return (true);
	return (false);
}
