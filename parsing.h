/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:08:58 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/01 00:57:53 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_quote
{
	bool	s_quote;
	bool	d_quote;
}	t_quote;

typedef struct s_parenthes
{
	t_tree				*p;
	struct s_parenthes	*next;
}	t_parenthes;

typedef struct s_parsing
{
	t_tree		*tree;
	t_operand	operand;
	t_parenthes	*save;
	int			parenthes;
}	t_parsing;

t_tree		*parse(char *line);
t_tree		*new_node(t_tree *parent, t_operand operand, char *name);
void		insert_node(t_tree *node, t_operand operand, char *name);
bool		is_whitespace(char c);
bool		is_special(char c);
bool		is_quoted(t_quote *scope, char c);
t_operand	is_operand(char **line);
char		*strdup_to_next_operand(char **line);
char		*strdup_to_next_space(char **line);
void		insert_node(t_tree *node, t_operand operand, char *name);
void		save_parenthesis(t_parsing *pars);
t_tree		*get_last_save(t_parsing *pars);
void		fill_tree(t_parsing *pars, char **line);
void		fill_file(t_parsing *pars, char **line);
void		fill_pipe(t_parsing *pars);
void		fill_operator(t_parsing *pars);
void		fill_cmd(t_parsing *pars, char **line);
void		free_tree(t_tree **tree);

#include <stdio.h>
#include <unistd.h>
void	print_node(t_tree *node);
void	print_tree(t_tree *tree, int space);

#endif
