/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs_write_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:30:18 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/12 18:30:18 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parsing.h"

static int	add_to_file(char *line, int fd)
{
	if (ft_putstr_fd(line, fd) == 1)
	{
		free(line);
		return (1);
	}
	if (ft_putchar_fd('\n', fd) == 1)
	{
		free(line);
		return (1);
	}
	return (0);
}

int	write_file(int fd, char *delim)
{
	char	*line;

	while (1)
	{
		if (g_s != 0)
			return (1);
		line = readline("> ");
		if (line == NULL)
		{
			if (ft_printf(2, \
			"minishell: warning: here-document delimited by") == -1)
				return (1);
			if (ft_printf(2, " end-of-file (wanted '%s')\n", delim) == -1)
				return (1);
			break;
		}
		if (ft_strcmp(line, delim) == 0)
			break;
		if (add_to_file(line, fd) == 1)
			return (1);
		free(line);
	}
	free(line);
	return (0);
}