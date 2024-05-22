/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:34:40 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/23 00:34:40 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_PIPE_H
# define EXEC_PIPE_H

int		*create_pipe(int pipe_fd[2]);
int		redirect_fd(int fd, int pipe_fd[2]);
int		exec_node_pipe(int pipe_fd[2], t_tree *node, int fd, t_utils *utils);
int		check_id_pipe(int id, t_utils *utils);

#endif
