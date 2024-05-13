/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:18:26 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/13 19:37:06 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	handle_parenthesis(t_parsing *pars, char **line);
static bool	pars_line(t_parsing *pars, char **line);

t_tree	*parse(char *line)
{
	t_parsing	pars;

	pars.save = NULL;
	pars.tree = NULL;
	pars.parenthes = 0;
	pars.head_line = line;
	if (!line)
		return (NULL);
	while (*line)
	{
		if (!pars_line(&pars, &line))
			return (NULL);
	}
	if (pars.save)
		return (clean_continue(&pars, &line, 3));
	if (pars.tree && ((pars.tree->operand == AND || pars.tree->operand == OR \
	|| pars.tree->operand == PIPE) && !pars.tree->right))
		return (clean_continue(&pars, &line, 2));
	line = pars.head_line;
	free(line);
	if (pars.tree)
		while (pars.tree->parent)
			pars.tree = pars.tree->parent;
	return (pars.tree);
}

static bool	pars_line(t_parsing *pars, char **line)
{
	while (**line && is_whitespace(**line))
		(*line)++;
	if (**line == '(' || **line == ')')
	{
		if (!handle_parenthesis(pars, line))
			return (false);
	}
	else if (**line)
	{
		pars->operand = is_operand(line);
		while (**line && is_whitespace(**line))
			(*line)++;
		if (!fill_tree(pars, line))
			return (false);
	}
	return (true);
}

static bool	handle_parenthesis(t_parsing *pars, char **line)
{
	t_tree		*saved_node;

	if (**line == '(')
	{
		if (!save_parenthesis(pars, line))
			return (false);
	}
	else
	{
		if (!pars->save || !pars->tree || ((pars->tree->operand == AND \
		|| pars->tree->operand == OR || pars->tree->operand == PIPE) && \
		!pars->tree->right))
			return (clean_continue(pars, line, 2), false);
		saved_node = get_last_save(pars);
		if (saved_node)
			return (pars->tree = saved_node, pars->parenthes = 1, \
			(*line)++, true);
		else
		{
			while (pars->tree->parent)
				pars->tree = pars->tree->parent;
			pars->parenthes = 2;
		}
	}
	return ((*line)++, true);
}

char	*strdup_to_next_operand(char **line, t_parsing *pars)
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
	if (scope.s_quote || scope.d_quote)
		return (clean_continue(pars, line, 3));
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (clean_continue(pars, line, 1));
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

char	*strdup_to_next_space(char **line, t_parsing *pars)
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
	if (scope.s_quote || scope.d_quote)
		return (clean_continue(pars, line, 3));
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (clean_continue(pars, line, 1));
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
