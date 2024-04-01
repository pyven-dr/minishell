/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:18:26 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/01 02:28:51 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tree	*parse(char *line)
{
	t_tree		*saved_node;
	t_parsing	pars;

	pars.save = NULL;
	pars.tree = NULL;
	pars.parenthes = 0;
	pars.head_line = line;
	if (!line)
		return (NULL);
	while (*line)
	{
		while (*line && is_whitespace(*line))
			line++;
		if (*line == '(' || *line == ')')
		{
			if (*line == '(')
				save_parenthesis(&pars, &line);
			else
			{
				saved_node = get_last_save(&pars);
				if (saved_node)
				{
					pars.tree = saved_node;
					pars.parenthes = 1;
				}
				else
				{
					while (pars.tree->parent)
						pars.tree = pars.tree->parent;
					pars.parenthes = 2;
				}
			}
			line++;
		}
		else if (*line)
		{
			pars.operand = is_operand(&line);
			while (*line && is_whitespace(*line))
				line++;
			fill_tree(&pars, &line);
		}
	}
	line = pars.head_line;
	free(line);
	if (pars.tree)
		while (pars.tree->parent)
			pars.tree = pars.tree->parent;
	return (pars.tree);
}

char	*strdup_to_next_operand(char **line)
{
	char	*str;
	int		i;
	t_quote	scope;

	scope.s_quote = false;
	scope.d_quote = false;
	i = 0;
	while ((*line)[i] && (!is_special((*line)[i]) || \
	is_quoted(&scope, (*line)[i])))
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

char	*strdup_to_next_space(char **line)
{
	char	*str;
	int		i;
	t_quote	scope;

	scope.s_quote = false;
	scope.d_quote = false;
	i = 0;
	while ((*line)[i] && ((!is_whitespace((*line)[i]) && \
	!is_special((*line)[i])) || is_quoted(&scope, (*line)[i])))
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (**line && ((!is_whitespace(**line) && \
	!is_special(**line)) || is_quoted(&scope, **line)))
	{
		str[i] = **line;
		(*line)++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
