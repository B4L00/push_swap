/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:05:31 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/14 13:15:27 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_min(int *t, int len, int n)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	min = t[i];
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (t[j] <= min)
				min = t[j];
			j++;
		}
		i++;
	}
	if (n <= min)
		return (1);
	return (0);
}

int	ft_is_max(int *t, int len, int n)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = t[i];
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (t[j] >= max)
				max = t[j];
			j++;
		}
		i++;
	}
	if (n > max)
		return (1);
	return (0);
}

void	ft_sort_end_a(t_stack *s)
{
	while (!ft_is_sort(s->a, s->len_a))
	{
		if (ft_is_rev_sort(s->a, s->len_a))
		{
			ft_ra(s);
			ft_sa(s->a, s->len_a);
		}
		if (*s->a < *(s->a + 1) && *s->a > *(s->a + s->len_a - 1))
			ft_rra(s);
		if (*s->a > *(s->a + 1) && *s->a < *(s->a + s->len_a - 1))
			ft_sa(s->a, s->len_a);
		if (*s->a > *(s->a + 1) && *s->a > *(s->a + s->len_a - 1))
			ft_ra(s);
		if (*s->a < *(s->a + 1) && *s->a < *(s->a + s->len_a - 1))
		{
			ft_sa(s->a, s->len_a);
			ft_ra(s);
		}
	}
}

/* void	ft_sort(t_stack *s)
{
	int	i_min;

	if (ft_is_sort(s->a, s->len_a))
		return ;
	while (s->len_a > 3)
	{
		ft_min(s->a, s->len_a, &i_min);
		if (i_min <= s->len_a / 2 && i_min != 0)
			ft_ra(s);
		if (i_min > s->len_a / 2 && i_min != 0)
			ft_rra(s);
		if (i_min == 0)
			ft_pb(s);
	}
	ft_sort_end_a(s);
	while (s->len_b > 0)
		ft_pa(s);
}
 */

int	ft_find_min(t_stack *s, int *i_min)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	min = s->a[i];
	while (i < s->len_a)
	{
		j = i;
		while (j < s->len_a)
		{
			if (s->a[j] <= min)
			{
				min = s->a[j];
				*i_min = j;
			}
			j++;
		}
		i++;
	}
	return (min);
}

void	ft_sort(t_stack *s)
{
	int i;

	i = 0;
	while (s->len_b > 0)
	{
		if (ft_is_max(s->a, s->len_a, *s->b))
		{
			if (ft_is_min(s->a, s->len_a, *s->a))
				ft_pa(s);
			else
				ft_rra(s);
		}
		else if (ft_is_min(s->a, s->len_a, *s->b))
		{
			if (ft_is_min(s->a, s->len_a, *s->a))
				ft_pa(s);
			else
				ft_rra(s);
		}
		else if (*s->b > *s->a && *s->b < *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
			ft_ra(s);
		else if (*s->b > *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
			ft_ra(s);
		else if (*s->b > *s->a && *s->b < *(s->a + 1)
			&& *s->b < *(s->a + s->len_a - 1))
			ft_ra(s); 
		else if (*s->b < *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
			ft_pa(s);
		else if (*s->b < *s->a && *s->b < *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
			ft_pa(s);
		else if (*s->b < *s->a && *s->b < *(s->a + 1)
			&& *s->b < *(s->a + s->len_a - 1))
			ft_rra(s);
		else if (*s->b > *s->a && *s->b > *(s->a + 1)
			&& *s->b < *(s->a + s->len_a - 1))
		{
			ft_rra(s);
		}
		else if (*s->b < *s->a && *s->b > *(s->a + 1)
			&& *s->b < *(s->a + s->len_a - 1))
			ft_rra(s);
/* 		else if (*s->b > *s->a && *s->b < *(s->a + 1)
			&& *s->b < *(s->a + s->len_a - 1)) */
		i++;
		if (i == 10000)
			break ;
	}
}
