/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_operand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:31:20 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/25 19:59:24 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*join_cmd(char *s1, char *s2);

void	fill_file(t_tree **tree, t_operand operand, char **line)
{
	if (!*tree)
		*tree = new_node(NULL, operand, strdup_to_next_space(line));
	else
    {
		insert_node(*tree, operand, strdup_to_next_space(line));
		(*tree)->parent->left = *tree;
		*tree = (*tree)->parent;
	}
} 

void	fill_pipe(t_tree **tree, t_operand operand, t_parenthes *save)
{
	while (save && save->next)
		save = save->next;
	while ((*tree)->parent && ( \
	(*tree)->parent->operand == SIMPLE_IN || \
	(*tree)->parent->operand == DOUBLE_IN || \
	(*tree)->parent->operand == SIMPLE_OUT || \
	(*tree)->parent->operand == DOUBLE_OUT || \
	(*tree)->parent->operand == PIPE) && \
	(!save || save->p != (*tree)->parent) && (*tree)->parent)
		*tree = (*tree)->parent;
	if ((*tree)->parent)
		insert_node(*tree, operand, NULL);
	else
		(*tree)->parent = new_node(NULL, operand, NULL);
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
	*tree = (*tree)->parent;
}

void	fill_cmd(t_tree **tree, t_operand operand, char **line)
{
	t_tree	*head;

	if (!*tree)
	{
		*tree = new_node(NULL, operand, strdup_to_next_operand(line));
	}
	else
	{
		if ((*tree)->operand == AND || (*tree)->operand == OR || (*tree)->operand == PIPE)
			(*tree)->right = new_node(*tree, operand, strdup_to_next_operand(line));
		else
		{
			head = *tree;
			while ((*tree)->left->operand == SIMPLE_IN || (*tree)->left->operand == DOUBLE_IN || \
			(*tree)->left->operand == SIMPLE_OUT || (*tree)->left->operand == DOUBLE_OUT)
				*tree = (*tree)->left;
			(*tree)->left->name = join_cmd((*tree)->left->name, strdup_to_next_operand(line));
			*tree = head;
		}
	}
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
