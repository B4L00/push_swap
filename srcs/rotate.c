/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:05:15 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/24 17:06:58 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_stack *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->a[i];
	while (i + 1 < s->len_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i] = tmp;
	ft_printf("ra\n");
}

void	ft_rb(t_stack *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->b[i];
	while (i + 1 < s->len_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i] = tmp;
	ft_printf("rb\n");
}

void	ft_rr(t_stack *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->a[i];
	while (i + 1 < s->len_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i] = tmp;
	i = 0;
	tmp = s->b[i];
	while (i + 1 < s->len_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i] = tmp;
	ft_printf("rr\n");
}
