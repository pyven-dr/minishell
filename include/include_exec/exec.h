/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:32:49 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/16 18:28:30 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_utils
{
	t_vector	*fds_vector;
	t_vector	*env_vector;
}				t_utils;

typedef int	(*t_exec_funcs)(t_tree *node, t_utils *utils);

int		exec(t_tree *node, t_utils *utils);
void	free_cmd(char **cmd);
int		exec_cmd(char **cmd, t_utils *utils, t_tree *root);
int		check_id(int id, t_utils *utils, t_tree *node);
int		dup_fd(int fd1, int fd2);
int		close_fds(t_utils *utils);
t_tree	*find_root(t_tree *node);
int		init_env(t_utils *utils, char **envp);
void	free_env_line(void *line);
int		ft_getenv(char *name, t_vector *env_vector);
char	**create_env(t_vector *env_vector);
int		change_exit_val(int val, t_utils *utils);
void	exec_loop(t_utils *utils);
void	free_utils(char **args, t_utils *utils);
int		nb_args(char **args);

#endif