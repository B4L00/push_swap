/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:05:21 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/11 09:56:03 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(int *a, int len)
{
	int	tmp;

	if (len < 2)
		return ;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	ft_printf("sa\n");
}

void	ft_sb(int *b, int len)
{
	int	tmp;

	if (len < 2)
		return ;
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
	ft_printf("sb\n");
}

void	ft_ss(t_stack *s)
{
	ft_sa(s->a, s->len_a);
	ft_sb(s->b, s->len_b);
	ft_printf("ss\n");
}

void	ft_pa(t_stack *s)
{
	int	i;
	int	tmp;

	i = 0;
	if (s->len_b == 0)
		return ;
	tmp = s->b[0];
	while (i + 1 < s->len_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	i = s->len_a;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[i] = tmp;
	s->len_a++;
	s->len_b--;
	ft_printf("pa\n");
}

void	ft_pb(t_stack *s)
{
	int	i;
	int	tmp;

	i = 0;
	if (s->len_a == 0)
		return ;
	tmp = s->a[0];
	while (i + 1 < s->len_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	i = s->len_b;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[i] = tmp;
	s->len_b++;
	s->len_a--;
	ft_printf("pb\n");
}
