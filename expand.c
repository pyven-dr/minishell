/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:59:51 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/08 13:55:55 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	get_env_line(char *line, char **env)
{
	int	i;
	int	len;
	
	i = 0;
	len = ft_strlen(line);
	while (env[i])
	{
		if (!ft_strncmp(line, env[i], len) && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_expand(char *line, char **env)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	if (!line)
		return (NULL);
	i = get_env_line(line, env);
	free(line);
	j = 0;
	while (i != -1 && env[i][j++] != '=')
		;
	k = 0;
	while (i != -1 && env[i][j + k])
		k++;
	s = malloc((k + 1) * sizeof(char));
	if (!s)
		return (NULL);
	k = 0;
	while (i != -1 && env[i][j + k])
	{
		s[k] = env[i][j + k];
		k++;
	}
	s[k] = '\0';
	return (s);
}
