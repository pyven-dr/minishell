/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:02:22 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/19 14:53:56 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_tree
{
	struct s_tree	*parent;
	struct s_tree	*right;
	struct s_tree	*left;
	struct s_cmd	*cmd;
	enum e_operand	operand;
}	t_tree;

typedef struct s_cmd
{
	char			**cmd;
	struct s_file	*file;
}	t_cmd;

typedef struct s_file
{
	char				*name;
	struct e_chevron	chevron;
}	t_file;

typedef enum e_operand
{
	AND,
	OR,
	PIPE,
	CMD,
}	t_operand;

typedef enum e_chevron
{
	SIMPLE,
	DOUBLE,
}	t_chevron;

#endif
