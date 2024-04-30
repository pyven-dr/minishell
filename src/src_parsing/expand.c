/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:25:13 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/30 22:37:18 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	get_size_tab(t_vector *double_tabs);
static char	**get_all_values(t_vector *double_tabs);
static char	**split_all_values(t_vector *wildcard);

char	**expand(char *line, t_vector *env)
{
	char		*expanded_line;
	char		**tab;
	t_vector	*wildcard;

	expanded_line = get_name(line, env);
	if (!expanded_line)
		return (NULL);
	if (!there_is_a_wildcard(expanded_line))
	{
		tab = ft_split_quoted(expanded_line);
		if (!tab)
			return (NULL);
		return (tab);
	}
	wildcard = ft_wildcard(expanded_line);
	if (!wildcard)
		return (NULL);
	return (split_all_values(wildcard));
}

static char	**split_all_values(t_vector *wildcard)
{
	char		**tab;
	size_t		i;
	t_vector	*double_tabs;

	i = 0;
	double_tabs = new_vector(2, sizeof(char **));
	if (!double_tabs)
		return (NULL);
	while (get_elem_vector(wildcard, i))
	{
		tab = ft_split_quoted(get_elem_vector(wildcard, i));
		if (!tab)
			return (NULL);
		if (add_vector(double_tabs, (void *)tab, free_tab))
			return (NULL);
		i++;
	}
	del_vector(wildcard, free);
	return (get_all_values(double_tabs));
}

static char	**get_all_values(t_vector *double_tabs)
{
	char	**return_tab;
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	return_tab = malloc((get_size_tab(double_tabs) + 1) * sizeof(char *));
	if (!return_tab)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	tab = get_elem_vector(double_tabs, i);
	while (tab)
	{
		while (tab[j])
		{
			return_tab[k] = remove_quote(tab[j]);
			j++;
			k++;
		}
		j = 0;
		i++;
		tab = get_elem_vector(double_tabs, i);
	}
	return_tab[k] = NULL;
	return (return_tab);
}

static size_t	get_size_tab(t_vector *double_tabs)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	**tab;

	i = 0;
	j = 0;
	count = 0;
	tab = get_elem_vector(double_tabs, i);
	while (tab)
	{
		while (tab[j++])
		 	;
		count += j;
		j = 0;
		i++;
		tab = get_elem_vector(double_tabs, i);
	}
	return (j);
}
