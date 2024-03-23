/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:08:58 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/23 02:47:51 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct s_quote
{
	bool	s_quote;
	bool	d_quote;
}	t_quote;

t_tree		*new_node(t_tree *parent, t_operand operand, char *name);
bool		is_whitespace(char c);
bool		is_special(char c);
bool		is_quoted(t_quote *scope, char c);
t_operand	is_operand(char **line);
char		*strdup_to_next_operand(char **line);

#endif
