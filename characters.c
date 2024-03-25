/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:26:56 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/25 17:28:58 by sabitbol         ###   ########.fr       */
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
		return ((*line)++, AND);
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
	|| c == '('  || c == ')' || c == '\'' || c == '"')
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
