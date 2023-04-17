/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:34:59 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/17 10:10:48 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pre_sort(t_stack *s, int pivot)
{
	int	start;

	start = *s->a;
	ft_ra(s);
	while (*s->a != start)
	{
		if (*s->a >= pivot)
			ft_pb(s);
		else
			ft_ra(s);
	}
	if (*s->a >= pivot)
		ft_pb(s);
}

void	ft_final_pre_sort(t_stack *s)
{
	while (s->len_a > 3)
		ft_pb(s);
	ft_sort_end_a(s);
}
