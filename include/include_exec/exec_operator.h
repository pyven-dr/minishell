/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:31:47 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/23 00:31:47 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_OPERATOR_H
# define EXEC_OPERATOR_H

int		exec_pipe(t_tree *node, t_utils *utils);
int		exec_and(t_tree *node, t_utils *utils);
int		exec_or(t_tree *node, t_utils *utils);

#endif
