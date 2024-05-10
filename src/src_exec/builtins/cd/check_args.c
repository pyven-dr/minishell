/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:54:20 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/27 16:54:57 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*get_home(t_utils *utils)
{
	t_env	*home;
	int		home_pos;
	char	*home_val;

	home_pos = ft_getenv("HOME", utils->env_vector);
	if (home_pos == -1)
	{
		ft_printf(2, "minishell: cd: HOME not set\n");
		return (NULL);
	}
	home = get_elem_vector(utils->env_vector, home_pos);
	home_val = ft_strdup(home->value);
	if (home_val == NULL)
	{
		perror("minishell: cd");
		return (NULL);
	}
	return (home_val);
}

char	*check_args_cd(char **args, t_utils *utils)
{
	int	nb;

	nb = nb_args(args);
	if (nb > 2)
	{
		ft_printf(2, "minishell: cd: too many arguments\n");
		return (NULL);
	}
	if (nb == 1)
		return (get_home(utils));
	return (args[1]);
}
