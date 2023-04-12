/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:24:58 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/17 14:25:00 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while ((*lst)-> next)
	{
		tmp = (*lst)-> next;
		ft_lstdelone((*lst), (*del));
		(*lst) = tmp;
	}
	tmp = (*lst)-> next;
	ft_lstdelone((*lst), (*del));
	(*lst) = NULL;
}
