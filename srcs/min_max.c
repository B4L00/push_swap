/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:49:12 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/17 13:49:41 by larmenou         ###   ########.fr       */
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
