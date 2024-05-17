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
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>

# define ERR_PWD \
"pwd: error retrieving current directory: cannot access parent directories"
# define ERR_PDW_CD \
"cd: error retrieving current directory: cannot access parent directories"
# define ERR_CD_HOME "minishell: cd: HOME not set\n"
# define ERR_CD_ARG "minishell: cd: too many arguments\n"
# define ERR_CD_FILE "minishell: cd: %s: No such file or directory\n"
# define ERR_CD_DIR "minishell: cd: %s: Not a directory\n"
# define ERR_CD_NAME "minishell: cd: %s: File name too long\n"
# define ERR_EOF_HD \
"minishell: warning: here-document delimited by end-of-file (wanted '%s')\n"

typedef struct s_utils
{
	t_vector	*fds_vector;
	t_vector	*env_vector;
}				t_utils;

typedef int	(*t_exec_funcs)(t_tree *node, t_utils *utils);

int		exec(t_tree *node, t_utils *utils);
void	free_cmd(char **cmd);
int		exec_cmd(char **cmd, t_utils *utils, t_tree *root);
int		check_id(int id, t_utils *utils);
int		dup_fd(int fd1, int fd2);
int		close_fds(t_utils *utils);
t_tree	*find_root(t_tree *node);
int		init_env(t_utils *utils, char **envp);
void	free_env_line(void *line);
int		ft_getenv(char *name, t_vector *env_vector);
char	**create_env(t_vector *env_vector);
int		change_exit_val(int val, t_utils *utils);
void	exec_loop(t_utils *utils);
int		check_sig(t_utils *utils);
void	free_utils(char **args, t_utils *utils);
int		print_sig_cmd(void);

// Find command //

char	*check_absolute_path(char *cmd);
char	*find_command(char **path, char *command);
char	*get_cmd_path(char *command, t_vector *env_vector);

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
int		expand_redirect(t_tree *node, t_vector *env_vector);
int		remove_fds_vector(int oldfd, t_vector *fds_vector);

// Pipes //

int		*create_pipe(int pipe_fd[2]);
int		redirect_fd(int fd, int pipe_fd[2]);
int		exec_node_pipe(int pipe_fd[2], t_tree *node, int fd, t_utils *utils);

// Heredocs //

char	*random_name(void);
char	*create_heredoc(char *delim, t_vector *env);
int		make_all_heredocs(t_tree *node, t_vector *env);
int		write_file(int fd, char *delim, t_vector *env);
void	del_all_heredocs(t_tree *node);

// Signals //

void	init_sig(void);
void	sig_exec(void);
void	sig_end_exec(void);
void	signal_handler(int signal);

// Builtins //

int		check_builtins(char **cmd, t_utils *utils, t_tree *tree);
int		nb_args(char **args);
int		echo(char **args);
int		pwd(void);
int		exit_builtin(char **args, t_utils *utils);
int		env(t_vector *env);
int		unset(char **args, t_utils *utils);

// Export //

int		export(char **arg, t_utils *utils);
int		get_env_line(char *arg, t_env *env);
int		display_env(t_vector *env);
int		check_arg_env(char *arg);
int		add_env(char *arg, t_vector *env_vector);
int		replace_env(t_vector *env_vector, char *arg);

// CD //

int		cd(char **args, t_utils *utils);
char	*check_args_cd(char **args, t_utils *utils);
int		split_cdpath(char ***cdpath_split, t_utils *utils);
char	*check_cdpath(t_utils *utils, char *directory, int *print_path);
char	*canonize(char *curpath, char *directory);
void	remove_dot(char ***components, int nb_components);
int		remove_dotdot(char ***components, int nb_components, char *directory);
char	*join_path(char **components, int last, int nb_components);
int		check_file(char **components, int last, int nb_components, \
					char *directory);
char	*add_fisrt_slash(char *curpath, int start_slash);
char	*check_pathmax(char *curpath, char *directory);
char	*add_pwd(char *curpath);
int		change_env(char *pwd, char *oldpwd, t_utils *utils);
int		change_dir(char *curpath, t_utils *utils);
int		check_curpath(char *curpath, char *directory);
char	*get_curpath(char *directory, t_utils *utils, int *print_path);

#endif