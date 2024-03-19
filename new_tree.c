/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:35:50 by sabitbol          #+#    #+#             */
/*   Updated: 2024/03/19 16:15:15 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



t_file	*new_file(char *file_name, t_chevron chevron)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->name = file_name;
	file->chevron = chevron;
	return (file);
}

t_cmd	*new_cmd(char *cmd, t_file *file)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->file = file;
	cmd->cmd = cmd;
	return (cmd);
}

