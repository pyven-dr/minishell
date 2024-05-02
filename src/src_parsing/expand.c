/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:25:13 by sabitbol          #+#    #+#             */
/*   Updated: 2024/05/02 02:16:03 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	get_size_tab(t_vector *double_tabs);
static char		**get_all_values(t_vector *double_tabs);
static char		**split_all_values(char **tab_splitted);
static char		**get_tab_from_vector(t_vector *wildcard);

char	**expand(char *line, t_vector *env)
{
	char		*expanded_line;
	char		**tab;

	expanded_line = get_name(line, env);
	if (!expanded_line)
		return (NULL);
	if (!there_is_a_wildcard(expanded_line))
	{
		tab = ft_split_quoted(expanded_line);
		if (!tab)
			return (NULL);
		free(expanded_line);
		//remove all quote from every case of the tab
		return (tab);
	}
	tab = ft_split_quoted(expanded_line);
	if (!tab)
		return (NULL);
	free(expanded_line);
	return (split_all_values(tab));
}

static char	**split_all_values(char **tab_splitted)
{
	char		**tab;
	size_t		i;
	t_vector	*double_tabs;

	i = 0;
	double_tabs = new_vector(1, sizeof(char **));
	if (!double_tabs)
		return (NULL);
	while (tab_splitted[i])
	{
		if (!there_is_a_wildcard(tab_splitted[i]))
		{
			tab = malloc(2 * sizeof(char *));
			tab[0] = ft_strdup(tab_splitted[i]);
			tab[1] = NULL;
		}
		else
			tab = get_tab_from_vector(ft_wildcard(tab_splitted[i]));
		if (add_vector(double_tabs, &tab, free_tab))
			return (NULL);
		i++;
	}
	free_tab(tab_splitted);
	return (get_all_values(double_tabs));
}

// void	free_tab_value(void *value)
// {
// 	char	***tab;
// 	size_t	i;

// 	i = 0;
// 	tab = value;
// 	while ((*tab)[i])
// 	{
// 		free((*tab)[i]);
// 		i++;
// 	}
// 	free(*tab);
// }

static char	**get_all_values(t_vector *double_tabs)
{
	char	**return_tab;
	char	***tab;
	size_t	i;
	size_t	j;
	size_t	k;

	return_tab = malloc((get_size_tab(double_tabs) + 1) * sizeof(char *));
	if (!return_tab)
		return (NULL);
	i = 0;
	j = -1;
	k = 0;
	tab = get_elem_vector(double_tabs, i);
	while (tab)
	{
		while ((*tab)[++j])
		{
			return_tab[k] = remove_quote((*tab)[j]);
			k++;
		}
		j = -1;
		tab = get_elem_vector(double_tabs, ++i);
	}
	del_vector(double_tabs, &free_value);
	return (return_tab[k] = NULL, return_tab);
}

static size_t	get_size_tab(t_vector *double_tabs)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	***tab;

	i = 0;
	j = 0;
	count = 0;
	tab = get_elem_vector(double_tabs, i);
	while (tab)
	{
		while ((*tab)[j])
			j++;
		count += j;
		j = 0;
		i++;
		tab = get_elem_vector(double_tabs, i);
	}
	return (count);
}

static char	**get_tab_from_vector(t_vector *wildcard)
{
	size_t	i;
	char	**tab;
	char	**temp;

	tab = malloc((wildcard->size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	temp = get_elem_vector(wildcard, i);
	while (temp)
	{
		tab[i] = ft_strdup(*temp);
		if (!tab[i])
		{
			while (i-- > 0)
				free(tab[i]);
			return (NULL);
		}
		i++;
		temp = get_elem_vector(wildcard, i);
	}
	tab[i] = NULL;
	del_vector(wildcard, &free_value);
	return (tab);
}
