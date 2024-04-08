/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:26:00 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/08 14:30:43 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*strdup_var(char **line);
static char	*replace_vars(char *line, char **env);

char	*get_file(char *line, char **env)
{
	char	*s;

	if (!line)
		return (NULL);
	s = replace_vars(line, env);
	if (!s)
		return (NULL);
	//s = remove_quotes(s);
	printf("result : %s\n", s);
	free(s);
	return (NULL);
}

static char	*replace_vars(char *line, char **env)
{
	char	*s;
	char	*head;
	int		i;
	t_quote	scope;

	scope.s_quote = false;
	scope.d_quote = false;
	i = 0;
	head = line;
	s = malloc(1 * sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '\0';
	while (line[i])
	{
		is_quoted(&scope, line[i]);
		if (line[i] == '$' && !scope.s_quote)
		{
			line[i] = '\0';
			s = ft_strjoin(s, ft_strdup(line));
			if (!s)
				return (NULL);
			line += i + 1;
			s = ft_strjoin(s, ft_expand(strdup_var(&line), env));
			if (!s)
				return (NULL);
			i = -1;
		}
		i++;
	}
	s = ft_strjoin(s, ft_strdup(line));
	if (!s)
		return (NULL);
	line = head;
	//free(line);
	return (s);
}

static char	*strdup_var(char **line)
{
	int		i;
	char	*s;

	i = 0;
	while ((*line)[i] && (*line)[i] != '\'' && (*line)[i] != '"' && (*line)[i] != '$' \
	&& !is_whitespace((*line)[i]))
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (**line && **line != '\'' && **line != '"' && **line != '$' \
	&& !is_whitespace(**line))
	{
		s[i] = **line;
		i++;
		(*line)++;
	}
	s[i] = '\0';
	return (s);
}
