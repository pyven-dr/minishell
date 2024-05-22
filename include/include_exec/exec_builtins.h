/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:39:47 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/23 00:39:47 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_BUILTINS_H
# define EXEC_BUILTINS_H

int		check_builtins(char **cmd, t_utils *utils, t_tree *tree);
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
