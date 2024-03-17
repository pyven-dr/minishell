/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:02:22 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/17 15:07:57 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_tree
{
	struct s_tree	*right;
	struct s_tree	*left;
	struct s_cmd	*pipex;
	enum e_operand	operand;
}	t_tree;

typedef struct s_cmd
{
	char	**cmd;
	char	**fd;
}	t_cmd;

typedef enum e_operand
{
	AND,
	OR,
	CMD,
}	t_operand;

#endif
