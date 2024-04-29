/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cdpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:27:22 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/29 01:27:22 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*get_cdpath(t_vector *env_vector)
{
	t_env	*env_line;
	int		pos_cdpath;

	pos_cdpath = ft_getenv("CDPATH", env_vector);
	if (pos_cdpath == -1)
		return (NULL);
	env_line = get_elem_vector(env_vector, pos_cdpath);
	return (env_line->value);
}

static int	fill_cdpath(t_vector *cdpath, char *base_cdpath)
{
	int	i;

	i = 0;
	while (base_cdpath[i] != '\0')
	{
		if (base_cdpath[i] == ':' && base_cdpath[i - 1] != '/')
			if (add_vector(cdpath, "/", NULL) == -1)
				return (-1);
		if (add_vector(cdpath, &base_cdpath[i], NULL) == -1)
			return (-1);
		if (base_cdpath[i] == ':' && base_cdpath[i + 1] == ':')
			if (add_vector(cdpath, ".", NULL) == -1)
				return (-1);
		i++;
	}
	return (i);
}

static t_vector	*init_cdpath(t_utils *utils)
{
	t_vector	*cdpath;
	char		*base_cdpath;
	int			i;

	cdpath = new_vector(10, sizeof(char));
	if (cdpath == NULL)
		return (NULL);
	base_cdpath = get_cdpath(utils->env_vector);
	if (base_cdpath == NULL)
		return (NULL);
	if (base_cdpath[0] == ':')
		if (add_vector(cdpath, ".", NULL) == -1)
			return (NULL);
	i = fill_cdpath(cdpath, base_cdpath);
	if (i == -1)
		return (NULL);
	if (base_cdpath[i - 1] == ':')
		if (add_vector(cdpath, ".", NULL) == -1)
			return (NULL);
	if (base_cdpath[i - 1] != '/')
		if (add_vector(cdpath, "/", NULL) == -1)
			return (NULL);
	return (cdpath);
}

char	**split_cdpath(t_utils *utils)
{
	char		*cdpath;
	//char		**split_cdpath;
	t_vector	*vector;
	size_t 		i;
	char 		letter;

	i = 0;
	vector = init_cdpath(utils);
	cdpath = ft_calloc(vector->size + 1, sizeof(char));
	while (i < vector->size)
	{
		letter = *(char*)get_elem_vector(vector, i);
		cdpath[i] = letter;
		i++;
	}
	printf("%s\n", cdpath);
	//split_cdpath = ft_split(cdpath, ':');
	//if (split_cdpath == NULL)
		return (NULL);
	//return (split_cdpath);
}