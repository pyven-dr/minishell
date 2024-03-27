/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_operand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:31:20 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/27 15:06:23 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*join_cmd(char *s1, char *s2);

void	fill_file(t_tree **tree, t_operand operand, char **line)
{
	if (!*tree)
		*tree = new_node(NULL, operand, strdup_to_next_space(line));
	else if ((*tree)->operand == AND || (*tree)->operand == OR || (*tree)->operand == PIPE)
	{
		(*tree)->right = new_node(*tree, operand, strdup_to_next_space(line));
		*tree = (*tree)->right;
	}
	else if ((*tree)->operand != CMD)
	{
		(*tree)->left = new_node(*tree, operand, strdup_to_next_space(line));
		*tree = (*tree)->left;
	}
	else if (!(*tree)->parent)
	{
		(*tree)->parent = new_node(NULL, operand, strdup_to_next_space(line));
		(*tree)->parent->left = *tree;
	}
	else
		insert_node(*tree, operand, strdup_to_next_space(line));
}

void	fill_pipe(t_tree **tree, t_operand operand, t_parenthes *save)
{
	while (save && save->next)
		save = save->next;
	while ((!save || save->p != (*tree)->parent) && (*tree)->parent \
	&& (*tree)->parent->operand != AND && (*tree)->parent->operand != OR) 
		*tree = (*tree)->parent;
	if ((*tree)->parent)
		insert_node(*tree, operand, NULL);
	else
	{
		(*tree)->parent = new_node(NULL, operand, NULL);
		(*tree)->parent->left = *tree;
	}
	*tree = (*tree)->parent;
}

void	fill_operator(t_tree **tree, t_operand operand, t_parenthes *save)
{
	while (save && save->next)
		save = save->next;
	while ((!save || save->p != (*tree)->parent) && (*tree)->parent)
		*tree = (*tree)->parent;
	if ((*tree)->parent)
		insert_node(*tree, operand, NULL);
	else
		(*tree)->parent = new_node(NULL, operand, NULL);
	(*tree)->parent->left = *tree;
	*tree = (*tree)->parent;
}

void	fill_cmd(t_tree **tree, t_operand operand, char **line)
{
	if (!*tree)
		*tree = new_node(NULL, operand, strdup_to_next_operand(line));
	else if ((*tree)->operand == AND || (*tree)->operand == OR || (*tree)->operand == PIPE)
	{
		(*tree)->right = new_node(*tree, operand, strdup_to_next_operand(line));
		*tree = (*tree)->right;
	}
	else if ((*tree)->operand == CMD)
	{
		(*tree)->name = join_cmd((*tree)->name, strdup_to_next_operand(line));
	}
	else if (!(*tree)->left)
	{
		(*tree)->left = new_node(*tree, operand, strdup_to_next_operand(line));
		*tree = (*tree)->left;
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
