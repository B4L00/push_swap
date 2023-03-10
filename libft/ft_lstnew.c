/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:14:02 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/14 13:14:03 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l -> content = content;
	l -> next = 0;
	return (l);
}

/*
#include <stdio.h>
int main()
{
	t_list *l = ft_lstnew(((void*)0));
	printf("%p\n", l -> content);
	return 0;
}
*/