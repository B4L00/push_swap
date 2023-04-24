/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:05:31 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/24 14:57:25 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_end_a(t_stack *s)
{
	if (!s->a)
		return ;
	while (!ft_is_sort(s->a, s->len_a))
	{
		if (ft_is_rev_sort(s->a, s->len_a))
		{
			ft_ra(s);
			ft_sa(s->a, s->len_a);
		}
		else if (*s->a < *(s->a + 1) && *s->a > *(s->a + s->len_a - 1))
			ft_rra(s);
		else if (*s->a > *(s->a + 1) && *s->a < *(s->a + s->len_a - 1))
			ft_sa(s->a, s->len_a);
		else if (*s->a > *(s->a + 1) && *s->a > *(s->a + s->len_a - 1))
			ft_ra(s);
		else if (*s->a < *(s->a + 1) && *s->a < *(s->a + s->len_a - 1))
		{
			ft_sa(s->a, s->len_a);
			ft_ra(s);
		}
	}
}

void	ft_sort_suite(t_stack *s)
{
	if (*s->b < *s->a && *s->b < *(s->a + 1)
		&& *s->b > *(s->a + s->len_a - 1))
		ft_pa(s);
	else if (*s->b < *s->a && *s->b < *(s->a + 1)
		&& *s->b < *(s->a + s->len_a - 1))
		ft_rra(s);
	else if (*s->b > *s->a && *s->b > *(s->a + 1)
		&& *s->b < *(s->a + s->len_a - 1))
		ft_rra(s);
	else if (*s->b < *s->a && *s->b > *(s->a + 1)
		&& *s->b < *(s->a + s->len_a - 1))
		ft_rra(s);
	else if (*s->b < *s->a && *s->b > *(s->a + 1)
		&& *s->b > *(s->a + s->len_a - 1))
		ft_pa(s);
	else if (*s->b > *s->a && *s->b < *(s->a + 1)
		&& *s->b < *(s->a + s->len_a - 1))
		ft_ra(s);
}

void	ft_sort(t_stack *s)
{
	while (s->len_b > 0)
	{
		if (ft_is_max(s->a, s->len_a, *s->b))
		{
			if (ft_is_min(s->a, s->len_a, *s->a))
				ft_pa(s);
			else
				ft_ra(s);
		}
		else if (ft_is_min(s->a, s->len_a, *s->b))
		{
			if (ft_is_min(s->a, s->len_a, *s->a))
				ft_pa(s);
			else
				ft_ra(s);
		}
		else if (*s->b > *s->a && *s->b < *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
			ft_ra(s);
		else if (*s->b > *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
			ft_ra(s);
		else
			ft_sort_suite(s);
	}
}

void	ft_sort_5(t_stack *s)
{
	int	min;
	int	i_min;

	ft_final_pre_sort(s);
	ft_sort(s);
	min = ft_find_min(s, &i_min);
	while (*s->a != min)
	{
		if (i_min <= s->len_a / 2)
			ft_ra(s);
		else
			ft_rra(s);
	}
}

void	ft_main_sort(t_stack *s)
{
	int	i;
	int	min;
	int	i_min;

	i = 5;
	while (i > 0)
	{
		s->pivot = ft_pivot(s, i--);
		ft_pre_sort(s, s->pivot);
	}
	ft_final_pre_sort(s);
	while (s->len_b > 0)
		ft_decision(s);
	//ft_sort(s);
	min = ft_find_min(s, &i_min);
	while (*s->a != min)
	{
		if (i_min <= s->len_a / 2)
			ft_ra(s);
		else
			ft_rra(s);
	}
}
