/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:04:50 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/05/16 18:00:48 by sabitbol         ###   ########.fr       */
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

static void	free_utils_exit(char **args, t_utils *utils, t_tree *tree)
{
	if (tree != NULL)
		free_tree(&tree);
	if (args != NULL)
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

int	exit_builtin(char **args, t_utils *utils, t_tree *tree)
{
	char	exit_status;

	if (nb_args(args) > 2)
		return (ft_putstr_fd("minishell: exit: too many arguments\n", 2), 1);
	if (nb_args(args) == 1 || args == NULL)
	{
		exit_status = (char)get_exit_status(utils);
		free_utils_exit(args, utils, tree);
		if (write(2, "exit\n", 5) == -1)
			exit(1);
		exit(exit_status);
	}
	if (check_arg(args[1]) == 1)
	{
		free_utils_exit(args, utils, tree);
		ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		exit(2);
	}
	exit_status = (char)ft_atoi(args[1]);
	free_utils_exit(args, utils, tree);
	if (write(2, "exit\n", 5) == -1)
		exit(1);
	exit(exit_status);
}
