/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:02:22 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/23 02:55:00 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
	enum e_operand	operand;
}	t_tree;

#endif
