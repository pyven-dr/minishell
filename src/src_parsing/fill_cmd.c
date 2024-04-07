/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:22:08 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/02 18:39:57 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*join_cmd(char *s1, char *s2);
static void	fill_cmd_2(t_parsing *pars, char **line, char *name);

void	fill_cmd(t_parsing *pars, char **line)
{
	char	*name;

	name = strdup_to_next_operand(line, pars);
	if (!name)
		clean_exit(pars, line, 1);
	else if (!*name)
		clean_exit(pars, line, 2);
	if (!pars->tree)
	{
		pars->tree = new_node(NULL, pars->operand, name);
		if (!pars->tree)
			clean_exit(pars, line, 1);
	}
	else if (pars->tree->operand == AND || pars->tree->operand == OR \
	|| pars->tree->operand == PIPE)
	{
		pars->tree->right = new_node(pars->tree, pars->operand, name);
		if (!pars->tree->right)
			clean_exit(pars, line, 1);
		pars->tree = pars->tree->right;
	}
	else
		fill_cmd_2(pars, line, name);
}

static void	fill_cmd_2(t_parsing *pars, char **line, char *name)
{
	if (pars->tree->operand == CMD)
	{
		pars->tree->name = join_cmd(pars->tree->name, name);
		if (!pars->tree->name)
			clean_exit(pars, line, 1);
	}
	else if (!pars->tree->left)
	{
		pars->tree->left = new_node(pars->tree, pars->operand, name);
		if (!pars->tree->left)
			clean_exit(pars, line, 1);
		pars->tree = pars->tree->left;
	}
}

static char	*join_cmd(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	str = malloc((i + j + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = ' ';
	i++;
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	free(s2);
	return (str);
}
