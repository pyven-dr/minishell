/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:31:26 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/01 17:52:56 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*strdup_to_next_asterism(char **line);
static char	*improved_strstr(char *big, char *little);
static int	check_strstr(char **name, char **file, char **temp);
static bool	is_valid_name(char *name, char *file);

t_vector	*ft_wildcard(char *line)
{
	DIR				*current;
	struct dirent	*file;
	t_vector		*result;
	char			*temp;

	current = opendir(".");
	if (!current)
		printf("ALED");
	file = readdir(current);
	result = new_vector(1, sizeof(char *));
	if (!result)
		return (NULL);
	while (file)
	{
		if (is_valid_name(line, file->d_name))
		{
			temp = ft_strdup(file->d_name);
			if (!temp)
				return (NULL);
			if (add_vector(result, &temp, free))
				return (NULL);
		}
		file = readdir(current);
	}
	closedir(current);
	return (result);
}

static bool	is_valid_name(char *name, char *file)
{
	char	*temp;
	int		ret;

if (*name != '*')
	{
		temp = strdup_to_next_asterism(&name);
		if (!temp)
			printf("ALED\n");
		if (ft_strncmp_improved(temp, &file, strlen(temp)))
			return (free(temp), false);
		free(temp);
	}
	while (1)
	{
		while (*name && *name == '*')
				name++;
		if (!*name)
			return (true);
		temp = strdup_to_next_asterism(&name);
		if (!temp)
			printf("ALED\n");
		ret = check_strstr(&name, &file, &temp);
		if (ret != 2)
			return (ret);
	}
}

static int	check_strstr(char **name, char **file, char **temp)
{
	*file = improved_strstr(*file, *temp);
	if (!*file)
		return (free(*temp), 0);
	else if (!**file && !**name)
		return (free(*temp), 1);
	else if (!**name)
	{
		while (*file)
		{
			*file = improved_strstr(*file, *temp);
			if (*file && !**file)
				break ;
		}
		if (!*file)
			return (free(*temp), 0);
		else if (!**file)
			return (free(*temp), 1);
	}
	free(*temp);
	return (2);
}

static char	*strdup_to_next_asterism(char **line)
{
	char	*str;
	char	*head;
	size_t	i;
	size_t	j;
	t_quote	scope;

	scope.s_quote = false;
	scope.d_quote = false;
	i = 0;
	j = 0;
	head = *line;
	while ((*line)[i] && (is_quoted(&scope, (*line)[i]) || (*line)[i] != '*'))
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	*line = head;
	while (**line && (is_quoted(&scope, **line) || **line != '*'))
	{
		str[i] = **line;
		i++;
		(*line)++;
	}
	return (str[i] = '\0', str);
}

static char	*improved_strstr(char *big, char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*big)
	{
		while (little[i + j] && big[i])
		{
			while (little[i + j] == '"' || little[i + j] == '\'')
				j++;
			if (little[i + j] != big[i])
			{
				j = 0;
				i = 0;
				break ;
			}
			i++;
		}
		if (i != 0)
			return (big + i);
		big++;
	}
	return (NULL);
}
