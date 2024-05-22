/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_find_cmd.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:29:46 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/23 00:29:46 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_FIND_CMD_H
# define EXEC_FIND_CMD_H

char	*check_absolute_path(char *cmd);
char	*find_command(char **path, char *command);
char	*get_cmd_path(char *command, t_vector *env_vector);

#endif
