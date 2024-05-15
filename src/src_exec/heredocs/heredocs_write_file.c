/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs_write_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:30:18 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/15 19:00:08 by sabitbol         ###   ########.fr       */
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

int	write_file(int fd, char *delim, t_vector *env)
{
	char		*line;
	char		*expanded_line;
	t_is_quoted	s;

	s = remove_quote_heredoc(delim);
	if (!s.str)
		return (1);
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
			if (ft_printf(2, " end-of-file (wanted '%s')\n", s.str) == -1)
				return (1);
			free(line);
			free(s.str);
			return (0);
		}
		if (s.is_quoted == false)
		{
			expanded_line = get_name(line, env);
			free(line);
			line = expanded_line;
			if (!line)
				return (1);
		}
		if (ft_strcmp(line, s.str) == 0)
			return (free(line), free(s.str), 0);
		if (add_to_file(line, fd) == 1)
			return (free(s.str), 1);
		free(line);
	}
}
