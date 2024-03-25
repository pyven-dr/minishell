/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:32:49 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/20 01:32:49 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>

int		exec(t_tree *node);
void	free_cmd(char **cmd);
int		exec_cmd(char **cmd);
char	*check_absolute_path(char *cmd);
char	*find_command(char **path, char *command);
char	*get_cmd_path(char *command);
int		exec_and(t_tree *node);
int		exec_or(t_tree *node);
int		check_id(int id);
int		exec_pipe(t_tree *node);
int		exec_simple_in(t_tree *node);

#endif