/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:18:22 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/27 23:18:22 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*replace_chars(char *name)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (name[i] == '/' || name[i] == '\0')
			name[i] += 40;
		i++;
	}
	return (name);
}

char	*random_name(void)
{
	char	*name;
	int		fd_random;

	fd_random = open("/dev/urandom", O_RDONLY);
	if (fd_random == -1)
		return (NULL);
	name = malloc(sizeof(char) * 21);
	if (name == NULL)
	{
		close(fd_random);
		return (NULL);
	}
	if (read(fd_random, name, 20) == -1)
	{
		free(name);
		close(fd_random);
		return (NULL);
	}
	name[20] = '\0';
	if (close(fd_random) == -1)
		return (NULL);
	return (replace_chars(name));
}
