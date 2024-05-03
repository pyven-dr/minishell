/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:08:58 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/03 14:11:54 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "libft.h"
# include <stdlib.h>
# include <stddef.h>
# include <dirent.h>
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
	char		*head_line;
}	t_parsing;

t_tree		*parse(char *line);
t_tree		*new_node(t_tree *parent, t_operand operand, char *name);
void		insert_node(t_tree *node, t_operand operand, char \
**line, t_parsing *pars);
bool		is_whitespace(char c);
bool		is_special(char c);
bool		is_quoted(t_quote *scope, char c);
bool		is_quoted_sup(t_quote *scope, char c);
int			ft_strncmp_improved(const char *s1, char **s2, size_t n);
t_operand	is_operand(char **line);
char		*strdup_to_next_operand(char **line, t_parsing *pars);
char		*strdup_to_next_space(char **line, t_parsing *pars);
bool		save_parenthesis(t_parsing *pars, char **line);
t_tree		*get_last_save(t_parsing *pars);
bool		fill_tree(t_parsing *pars, char **line);
bool		fill_file(t_parsing *pars, char **line);
bool		fill_pipe(t_parsing *pars, char **line);
bool		fill_operator(t_parsing *pars, char **line);
bool		fill_cmd(t_parsing *pars, char **line);
void		free_tree(t_tree **tree);
void		clean_exit(t_parsing *pars, char **line, int exit_code);
char		*get_name(char *line, t_vector *env);
char		*strdup_var(char **line);
char		*ft_strjoin_free(char *s1, char *s2);
char		*remove_quote(char *s);
char		**ft_split_quoted(char *s);
bool		there_is_a_wildcard(char *s);
void		free_tab(void *content);
char		**expand(char *line, t_vector *env);
t_vector	*ft_wildcard(char *line);
void		free_value(void *value);
void		free_save(t_parenthes **save);
void		*clean_continue(t_parsing *pars, char **line, int code);

#include <stdio.h>
#include <unistd.h>
void	print_node(t_tree *node);
void	print_tree(t_tree *tree, int space);

#endif
