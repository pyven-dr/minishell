/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:20:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/30 13:20:16 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_read(int fd, char buffer[BUFFER_SIZE + 1], char *backup)
{
	ssize_t			fd_read;
	char			*temp;

	while (!ft_strchr(backup, '\n'))
	{
		fd_read = read(fd, buffer, BUFFER_SIZE);
		if (fd_read == -1)
			return (free(backup), ft_bzero(buffer, BUFFER_SIZE + 1), NULL);
		if (fd_read == 0)
			break ;
		buffer[fd_read] = '\0';
		temp = backup;
		backup = ft_strjoin(backup, buffer);
		free(temp);
		if (!backup)
			return (NULL);
	}
	return (backup);
}

static char	*get_lines(char *save)
{
	size_t		i;
	char		*temp;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\0')
		return (NULL);
	temp = ft_substr(save, i + 1, ft_strlen(save) - i);
	if (!temp)
		return (NULL);
	save[i + 1] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*backup;
	char			*save;
	static char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ft_strdup(buffer);
	if (!backup)
		return (NULL);
	save = line_read(fd, buffer, backup);
	if (!save)
		return (ft_bzero(buffer, BUFFER_SIZE + 1), NULL);
	backup = get_lines(save);
	if (!backup && !ft_strchr(save, '\0'))
		return (ft_bzero(buffer, BUFFER_SIZE + 1), free(save), NULL);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	ft_memcpy(buffer, backup, ft_strlen(backup));
	free(backup);
	if (save[0] == '\0')
		return (ft_bzero(buffer, BUFFER_SIZE + 1), free(save), NULL);
	return (save);
}
