/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:26:00 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/01 20:19:06 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"
#include "exec.h"

static char	*replace_vars(char *line, t_vector *env);
static char	*ft_expand(char *line, t_vector *env);

char	*get_name(char *line, t_vector *env)
{
	char	*s;

	if (!line)
		return (NULL);
	s = replace_vars(line, env);
	if (!s)
		return (NULL);
	return (s);
}

static char	*ft_expand(char *line, t_vector *env)
{
	int		i;
	t_env	*name;

	if (!line)
		return (NULL);
	i = ft_getenv(line, env);
	if (i == -1)
		return (NULL);
	name = get_elem_vector(env, i);
	free(line);
	return (name->value);
}

char	*strdup_var(char **line)
{
	int		i;
	char	*s;

	i = 0;
	while ((*line)[i] && !is_special((*line)[i]) && (*line)[i] != '$' \
	&& !is_whitespace((*line)[i]) && (*line)[i] != '*')
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (**line && !is_special(**line) && **line != '$' \
	&& !is_whitespace(**line) && **line != '*')
	{
		s[i] = **line;
		i++;
		(*line)++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	long	i;
	long	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	str = malloc((i + j + 2) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (free(s1), str);
}

static char	*replace_vars(char *line, t_vector *env)
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
			s = ft_strjoin_free(s, line);
			if (!s)
				return (write(2, ERR_MALLOC, 25), NULL);
			line += i + 1;
			var = ft_expand(strdup_var(&line), env);
			if (var != NULL)
				s = ft_strjoin_free(s, var);
			if (!s)
				return (write(2, ERR_MALLOC, 25), NULL);
			i = -1;
		}
		i++;
	}
	s = ft_strjoin_free(s, line);
	if (!s)
		return (write(2, ERR_MALLOC, 25), NULL);
	line = head;
	free(line);
	return (s);
}
