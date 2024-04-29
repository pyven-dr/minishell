/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:libs/libft/src/list/ft_lstnew_bonus.c
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 04:09:18 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/13 18:29:31 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
========
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabitbol <sabitbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:45:29 by sabitbol          #+#    #+#             */
/*   Updated: 2024/04/09 11:40:35 by sabitbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_UNCLOSED "Minishell : Unclosed quote or parenthesis\n"
# define ERR_SYNTHAX "Minishell : Synthax error\n"
# define ERR_MALLOC "Minishell : Error malloc\n"
# define ERR_AMBIGOUS "Minishell : Ambigous redictect\n"

#endif
>>>>>>>> parsing:include/include_parsing/error.h
