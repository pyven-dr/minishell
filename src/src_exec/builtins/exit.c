/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:04:50 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/04/08 19:04:50 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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
	free_cmd(args);
	free(args);
	del_vector(utils->fds_vector);
	free_tree(&utils->root);
	//free_cmd(utils->env);
}

int	exit_builtin(char **args, t_utils *utils)
{
	char	exit_status;

	if (nb_args(args) > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (1);
	}
	if (nb_args(args) == 1)
	{
		free_utils(args, utils);
		if (write(2, "exit\n", 5) == -1)
			exit(1);
		exit(0);
	}
	if (check_arg(args[1]) == 1)
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		exit(2);
	}
	exit_status = ft_atoi(args[1]);
	free_utils(args, utils);
	if (write(2, "exit\n", 5) == -1)
		exit(1);
	exit(exit_status);
}
