/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:18:26 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/21 20:35:22 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tree	*parse(char *line)
{
	t_tree	*tree;
	size_t	i;
	t_operand	operand;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && is_whitespace(line[i]))
		i++;
	while (line[i])
	{
		operand = is_operand(line);
		fill_tree(....)
	}
}

char	*strdup_to_next_operand(char *line, int *i)
{
	int	j;
	char	*str;

	j = *i;
	while (line[j] && is_operand[line + j] == CMD)
		j++;
	str = malloc((j - *i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (line[j + *i] && is_operand[line + *i + j] == CMD)
		str[j] = line[*i + j++];
	str[j] = '\0';
}

