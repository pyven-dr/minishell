/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:42:46 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/31 01:42:46 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	check_error(char *name, int fd)
{
	if (errno != 0)
	{
		close(fd);
		unlink(name);
		free(name);
		return (1);
	}
	return (0);
}

int	write_file(int fd, char *name, char *delim)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	if (check_error(name, fd) == 1)
		return (1);
	while (ft_strcmp(line, delim) != 0)
	{
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line(STDIN_FILENO);
		if (check_error(name, fd) == 1)
			return (1);
	}
	free(line);
	return (0);
}

char	*create_heredoc(char *delim)
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
	if (write_file(fd, name, delim) == 1)
		return (NULL);
	close(fd);
	return (name);
}
