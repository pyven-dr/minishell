/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_signal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:37:37 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/23 00:37:37 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_SIGNAL_H
# define EXEC_SIGNAL_H

# include <signal.h>
# include "exec.h"

void	init_sig(void);
void	sig_exec(void);
void	sig_end_exec(void);
void	signal_handler(int signal);
int		print_sig_cmd(void);
int		check_sig(t_utils *utils);
int		check_sig_pipe(t_utils *utils);

#endif
