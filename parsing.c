/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:18:26 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/23 04:22:55 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tree	*parse(char *line)
{
	t_tree		*tree;
	char		*head;
	t_operand	operand;
	t_parenthes	*save;

	save = NULL;
	tree = NULL;
	head = line;
	if (!line)
		return (NULL);
	while (*line)
	{
		while (*line && is_whitespace(*line))
			line++;
		operand = is_operand(&line);
		if (operand == 'CMD')
	}
	line = head;
	free(line);
}

char	*strdup_to_next_operand(char **line)
{
	char	*str;
	int	i;
	t_quote	scope;
	
	scope.s_quote = false;
	scope.d_quote = false;
	i = 0;
	while (*line[i] && (!is_special(*line[i]) || is_quoted(&scope, *line[i])))
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (**line && (!is_special(**line) || is_quoted(&scope, **line)))
	{
		str[i] = **line;
		(*line)++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
