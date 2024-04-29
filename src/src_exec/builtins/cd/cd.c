/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:50:41 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/27 17:16:33 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	check_first_component(char *directory)
{
	int	i;

	i = 0;
	while (directory[i] == '.')
		i++;
	if (i == 2 || i == 1)
		return (0);
	return (1);
}

int	cd(char **args, t_utils *utils)
{
	char	*directory;
	char	*curpath = NULL;

	directory = check_args_cd(args, utils);
	if (directory == NULL)
		return (1);
	if (directory[0] == '/' || check_first_component(directory) == 0)
		curpath = directory;
	else
		split_cdpath(utils);
	printf("%s\n", curpath);
	return (0);
}