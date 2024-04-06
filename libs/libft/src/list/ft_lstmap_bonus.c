/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:44:54 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/14 00:24:51 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*res;
	t_list	*next_node;
	void	*content;

	res = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		next_node = ft_lstnew(content);
		if (!next_node)
		{
			del(content);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, next_node);
		lst = lst->next;
	}
	return (res);
}
