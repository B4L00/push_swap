/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:34:59 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/26 14:05:35 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pre_sort(t_stack *s, int pivot)
{
	int	start;

	start = *s->a;
	ft_ra(s);
	while (*s->a != start && s->len_a > 3)
	{
		if (*s->a >= pivot)
			ft_pb(s);
		else
			ft_ra(s);
	}
	if (*s->a >= pivot && s->len_a > 3)
		ft_pb(s);
}

void	ft_final_pre_sort(t_stack *s)
{
	if (s->len_a == 2)
	{
		if (*s->a > *s->a + 1)
			ft_ra(s);
		return ;
	}
	while (s->len_a > 3)
		ft_pb(s);
	ft_sort_end_a(s);
}
