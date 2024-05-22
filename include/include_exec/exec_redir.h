/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:32:51 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/23 00:32:51 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_REDIR_H
# define EXEC_REDIR_H

int		exec_simple_in(t_tree *node, t_utils *utils);
int		exec_simple_out(t_tree *node, t_utils *utils);
int		exec_double_out(t_tree *node, t_utils *utils);
int		exec_double_in(t_tree *node, t_utils *utils);
int		dup_oldfd(t_utils *utils, int fd);
int		expand_redirect(t_tree *node, t_vector *env_vector);
int		remove_fds_vector(int oldfd, t_vector *fds_vector);

#endif
