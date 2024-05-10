/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:22:08 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/03 14:03:36 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	fill_cmd_2(t_parsing *pars, char **line, char *name);
static char	*join_cmd(char *s1, char *s2);

bool	fill_cmd(t_parsing *pars, char **line)
{
	char	*name;

	name = strdup_to_next_operand(line, pars);
	if (!name)
		return (NULL);
	else if (!*name)
		return (clean_continue(pars, line, 2));
	if (!pars->tree)
	{
		pars->tree = new_node(NULL, pars->operand, name);
		if (!pars->tree)
			return (clean_continue(pars, line, 1));
	}
	else if (pars->tree->operand == AND || pars->tree->operand == OR \
	|| pars->tree->operand == PIPE)
	{
		pars->tree->right = new_node(pars->tree, pars->operand, name);
		if (!pars->tree->right)
			return (clean_continue(pars, line, 1));
		pars->tree = pars->tree->right;
	}
	else
		if (fill_cmd_2(pars, line, name) == 1)
			return (NULL);
	return (true);
}

static int	fill_cmd_2(t_parsing *pars, char **line, char *name)
{
	if (pars->tree->operand == CMD)
	{
		pars->tree->name = join_cmd(pars->tree->name, name);
		if (!pars->tree->name)
		{
			clean_continue(pars, line, 1);
			return (1);
		}
	}
	else if (!pars->tree->left)
	{
		pars->tree->left = new_node(pars->tree, pars->operand, name);
		if (!pars->tree->left)
		{
			clean_continue(pars, line, 1);
			return (1);
		}
		pars->tree = pars->tree->left;
	}
	return (0);
}

static char	*join_cmd(char *s1, char *s2)
{
	char	*str;
	long	i;
	long	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	str = malloc((i + j + 2) * sizeof(char));
	if (!str)
		return (free(s1), free(s2), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = ' ';
	i++;
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (free(s1), free(s2), str);
}
