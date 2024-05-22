/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:36:00 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/23 00:36:00 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_HEREDOC_H
# define EXEC_HEREDOC_H

char	*random_name(void);
char	*create_heredoc(char *delim, t_vector *env);
int		make_all_heredocs(t_tree *node, t_vector *env);
int		write_file(int fd, char *delim, t_vector *env);
void	del_all_heredocs(t_tree *node);

#endif
