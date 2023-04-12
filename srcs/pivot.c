/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:06:29 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/12 10:52:34 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_pivot(t_stack *s, int cut)
{
	int	cpt;
	int	i;
	int	j;

	i = 0;
	while (i < s->len_a)
	{
		cpt = 1;
		j = 0;
		while (j < s->len_a)
		{
			if (s->a[i] < s->a[j])
				cpt++;
			j++;
		}
		if (cpt == s->len_a / cut)
			return (s->a[i]);
		i++;
	}
	return (s->a[i]);
}
