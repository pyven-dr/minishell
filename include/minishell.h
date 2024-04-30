/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:02:22 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/30 02:12:18 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>

typedef enum e_operand
{
	AND,
	OR,
	PIPE,
	CMD,
	SIMPLE_IN,
	DOUBLE_IN,
	SIMPLE_OUT,
	DOUBLE_OUT,
}	t_operand;

typedef struct s_tree
{
	struct s_tree	*parent;
	struct s_tree	*right;
	struct s_tree	*left;
	char			*name;
	t_operand		operand;
}	t_tree;

typedef struct s_env
{
	char	*name;
	char	*value;
	int		equal;
}	t_env;

void	free_tree(t_tree **tree);

typedef struct s_is_quoted
{
	char	*s;
	bool	is_quoted;
}	t_quoted;

#endif
