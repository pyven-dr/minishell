/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:26:00 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/19 17:05:19 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"

static char	*replace_vars(char *line, char **env);

char	**get_name(char *line, char **env)
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
	return (s[k] = '\0', s);
}

char	*strdup_var(char **line)
{
	int		i;
	char	*s;

	i = 0;
	while ((*line)[i] && !is_special((*line)[i]) && (*line)[i] != '$' \
	&& !is_whitespace((*line)[i]))
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (**line && !is_special(**line) && **line != '$' \
	&& !is_whitespace(**line))
	{
		s[i] = **line;
		i++;
		(*line)++;
	}
	s[i] = '\0';
	return (s);
}

static char	*replace_vars(char *line, char **env)
{
	char	*s;
	char	*head;
	char	*var;
	int		i;
	t_quote	scope;

	scope.s_quote = false;
	scope.d_quote = false;
	i = 0;
	head = line;
	s = malloc(1 * sizeof(char));
	if (!s)
		return (write(2, ERR_MALLOC, 25), NULL);
	s[0] = '\0';
	while (line[i])
	{
		is_quoted(&scope, line[i]);
		if (!scope.s_quote && line[i] == '$' && line[i + 1] != '\0')
		{
			line[i] = '\0';
			s = ft_strjoin(s, ft_strdup(line));
			if (!s)
				return (write(2, ERR_MALLOC, 25), NULL);
			line += i + 1;
			var = ft_expand(strdup_var(&line), env);
			if (!var)
				return (write(2, ERR_MALLOC, 25), NULL);
			s = ft_strjoin(s, var);
			if (!s)
				return (write(2, ERR_MALLOC, 25), NULL);
			i = -1;
		}
		i++;
	}
	s = ft_strjoin(s, ft_strdup(line));
	if (!s)
		return (write(2, ERR_MALLOC, 25), NULL);
	line = head;
	//free(line);
	return (s);
}
