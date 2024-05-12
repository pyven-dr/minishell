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
	if (write_file(fd, delim) == 1)
	{
		unlink(name);
		close(fd);
		return (NULL);
	}
	if (close(fd) == -1)
		return (NULL);
	return (name);
}
