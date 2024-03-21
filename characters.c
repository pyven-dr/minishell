/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:26:56 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/21 20:35:28 by sabitbol         ###   ########.fr       */
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
	if (**line == '&' && **(line + 1) == '&')
		return ((*line)++, AND);
	else if (**line == '|' && **(line + 1) == '|')
		return ((*line) += 2, OR);
	else if (**line == '|')
		return ((*line)++, PIPE);
	else if (**line == '<' && **(line + 1) == '<')
		return ((*line) += 2, DOUBLE_IN);
	else if (**line == '<')
		return (((*line)++, SIMPLE_IN);
	else if (**line == '>' && **(line + 1) == '>')
		return ((*line) += 2, DOUBLE_OUT);
	else if (**line == '>')
		return (((*line)++, SIMPLE_OUT);
	else
		return (CMD);
}

