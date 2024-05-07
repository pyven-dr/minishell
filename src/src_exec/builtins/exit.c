/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:04:50 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/18 12:40:27 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parsing.h"

static int	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	free_utils(char **args, t_utils *utils)
{
	free_tab(args);
	del_vector(utils->env_vector, free_env_line);
	del_vector(utils->fds_vector, NULL);
}

static int	get_exit_status(t_utils *utils)
{
	int		index;
	t_env	*env;

	index = ft_getenv("?", utils->env_vector);
	env = get_elem_vector(utils->env_vector, index);
	return (ft_atoi(env->value));
}

int	exit_builtin(char **args, t_utils *utils)
{
	char	exit_status;

	if (nb_args(args) > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	if (nb_args(args) == 1)
	{
		exit_status = (char)get_exit_status(utils);
		free_utils(args, utils);
		if (write(2, "exit\n", 5) == -1)
			exit(1);
		exit(exit_status);
	}
	if (check_arg(args[1]) == 1)
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		exit(2);
	}
	exit_status = (char)ft_atoi(args[1]);
	free_utils(args, utils);
	if (write(2, "exit\n", 5) == -1)
		exit(1);
	exit(exit_status);
}
