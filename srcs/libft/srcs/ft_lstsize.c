/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:47:36 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/16 10:47:38 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*l;
	int		cpt;

	l = lst;
	cpt = 0;
	if (!l)
		return (0);
	while (l -> next)
	{
		cpt++;
		l = l -> next;
	}
	cpt++;
	return (cpt);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	t_list *l;
	int actual;
	int expected;

	l = ft_lstnew(strdup("1"));
	l->next = ft_lstnew(strdup("2"));
	l->next->next = ft_lstnew(strdup("3"));
	expected = 3;
	actual = ft_lstsize(l);
	if (actual == expected)
		printf("OK");
	printf("KO i = %d", actual);
	return 0;
}
*/