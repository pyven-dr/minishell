/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_operand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:31:20 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/01 00:07:29 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*join_cmd(char *s1, char *s2);

void	fill_file(t_parsing *pars, char **line)
{
	if (!pars->tree)
		pars->tree = new_node(NULL, pars->operand, strdup_to_next_space(line));
	else if ((pars->tree->operand == AND || pars->tree->operand == OR \
	|| pars->tree->operand == PIPE) && !pars->parenthes)
	{
		pars->tree->right = new_node(pars->tree, pars->operand, strdup_to_next_space(line));
		pars->tree = pars->tree->right;
	}
	else if (pars->tree->operand != CMD && !pars->parenthes)
	{
		pars->tree->left = new_node(pars->tree, pars->operand, strdup_to_next_space(line));
		pars->tree = pars->tree->left;
	}
	else if ((!pars->tree->parent && pars->parenthes != 1) || pars->parenthes == 2)
	{
		pars->tree->parent = new_node(NULL, pars->operand, strdup_to_next_space(line));
		pars->tree->parent->left = pars->tree;
	}
	else
	{
		if (pars->parenthes)
		{
			pars->tree = pars->tree->right;
			pars->parenthes = 0;
		}
		insert_node(pars->tree, pars->operand, strdup_to_next_space(line));
	}
}

void	fill_pipe(t_parsing *pars)
{
	t_parenthes	*save;

	if (pars->parenthes)
	{
		if (pars->tree->operand == AND || pars->tree->operand == OR)
			pars->tree = pars->tree->right;
		pars->parenthes = 0;
	}
	save = pars->save;
	while (save && save->next)
		save = save->next;
	while ((!save || save->p != pars->tree->parent) && pars->tree->parent \
	&& pars->tree->parent->operand != AND && pars->tree->parent->operand != OR)
		pars->tree = pars->tree->parent;
	if (pars->tree->parent)
		insert_node(pars->tree, pars->operand, NULL);
	else
	{
		pars->tree->parent = new_node(NULL, pars->operand, NULL);
		pars->tree->parent->left = pars->tree;
	}
	pars->tree = pars->tree->parent;
}

void	fill_operator(t_parsing *pars)
{
	t_parenthes	*save;

	save = pars->save;
	while (save && save->next)
		save = save->next;
	while ((!save || save->p != pars->tree->parent) && pars->tree->parent)
		pars->tree = pars->tree->parent;
	if (pars->tree->parent)
		insert_node(pars->tree, pars->operand, NULL);
	else
	{
		pars->tree->parent = new_node(NULL, pars->operand, NULL);
		pars->tree->parent->left = pars->tree;
	}
	pars->tree = pars->tree->parent;
	if (pars->parenthes)
		pars->parenthes = 0;
}

void	fill_cmd(t_parsing *pars, char **line)
{
	if (!pars->tree)
		pars->tree = new_node(NULL, pars->operand, strdup_to_next_operand(line));
	else if (pars->tree->operand == AND || pars->tree->operand == OR \
	|| pars->tree->operand == PIPE)
	{
		pars->tree->right = new_node(pars->tree, pars->operand, strdup_to_next_operand(line));
		pars->tree = pars->tree->right;
	}
	else if (pars->tree->operand == CMD)
	{
		pars->tree->name = join_cmd(pars->tree->name, strdup_to_next_operand(line));
	}
	else if (!pars->tree->left)
	{
		pars->tree->left = new_node(pars->tree, pars->operand, strdup_to_next_operand(line));
		pars->tree = pars->tree->left;
	}
	else
		printf("WTF\n");
}

char	*join_cmd(char *s1, char *s2)
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
