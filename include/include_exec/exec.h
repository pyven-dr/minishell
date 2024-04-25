/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:32:49 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/25 15:03:39 by pyven-dr         ###   ########.fr       */
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
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_utils
{
	t_vector	*fds_vector;
	t_tree		*root;
	t_vector	*env_vector;
}				t_utils;

int		exec(t_tree *node, t_utils *utils);
void	free_cmd(char **cmd);
int		exec_cmd(char **cmd, t_utils *utils);
int		check_id(int id);
int		dup_fd(int fd1, int fd2);
void	close_fds(t_utils *utils);
t_tree	*find_root(t_tree *node);
void	free_env(t_vector *env);
int		init_env(t_utils *utils, char **envp);
void	free_env_line(void *line);
int		ft_getenv(char *name, t_vector *env_vector);

// Find command //

char	*check_absolute_path(char *cmd);
char	*find_command(char **path, char *command);
char	*get_cmd_path(char *command);

// Operators //

int		exec_pipe(t_tree *node, t_utils *utils);
int		exec_and(t_tree *node, t_utils *utils);
int		exec_or(t_tree *node, t_utils *utils);

// Redirections //

int		exec_simple_in(t_tree *node, t_utils *utils);
int		exec_simple_out(t_tree *node, t_utils *utils);
int		exec_double_out(t_tree *node, t_utils *utils);
int		exec_double_in(t_tree *node, t_utils *utils);
int		dup_oldfd(t_utils *utils, int fd);

// Pipes //

int		*create_pipe(int pipe_fd[2]);
int		redirect_fd(int fd, int pipe_fd[2]);
int		exec_node_pipe(int pipe_fd[2], t_tree *node, int fd, t_utils *utils);

// Heredocs //

char	*random_name(void);
char	*create_heredoc(char *delim);
int		make_all_heredocs(t_tree *node);

// Builtins //

int		check_builtins(char **cmd, t_utils *utils);
int		nb_args(char **args);
int		echo(char **args);
int		pwd(void);
int		exit_builtin(char **args, t_utils *utils);
int		env(t_vector *env);
int		unset(char **args, t_utils *utils);
int		export(char **args, t_utils *utils);
int		get_env_line(char *arg, t_env *env);
int		display_env(t_vector *env);
int		check_arg_env(char *arg);
int		add_env(char *arg, t_vector *env_vector);
int		replace_env(t_vector *env_vector, char *arg);

#endif