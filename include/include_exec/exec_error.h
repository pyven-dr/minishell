/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:25:04 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/23 00:25:04 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_ERROR_H
# define EXEC_ERROR_H

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

#endif
