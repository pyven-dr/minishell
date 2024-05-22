/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:42:46 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/15 18:54:41 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_heredoc.h"

char	*create_heredoc(char *delim, t_vector *env)
{
	int		fd;
	char	*name;

	name = random_name();
	if (name == NULL)
		return (NULL);
	fd = open(name, O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
	{
		free(name);
		return (NULL);
	}
	if (write_file(fd, delim, env) == 1)
	{
		unlink(name);
		close(fd);
		return (NULL);
	}
	if (close(fd) == -1)
		return (NULL);
	return (name);
}
