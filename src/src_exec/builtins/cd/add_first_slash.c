/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:37:30 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/01 04:37:30 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*add_fisrt_slash(char *curpath, int start_slash)
{
	char	*temp;

	if (start_slash == 1)
	{
		temp = curpath;
		curpath = ft_strjoin("/", temp);
		free(temp);
		if (curpath == NULL)
			return (NULL);
	}
	return (curpath);
}
