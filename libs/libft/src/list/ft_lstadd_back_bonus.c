/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:22:59 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/13 22:32:28 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*act;

	if (*lst == NULL)
		*lst = new;
	else
	{
		act = *lst;
		while (act->next != NULL)
			act = act->next;
		act->next = new;
	}
}
