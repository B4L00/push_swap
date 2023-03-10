/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:03:32 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/23 08:38:09 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*newlst;
	t_list	*start;

	if (!lst)
		return (NULL);
	newlst = ft_lstnew((*f)(lst -> content));
	if (!newlst)
		return (NULL);
	start = newlst;
	lst = lst -> next;
	while (lst != NULL)
	{
		newlst -> next = ft_lstnew((*f)(lst -> content));
		if (!newlst -> next)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		newlst = newlst -> next;
		lst = lst -> next;
	}
	return (start);
}
