/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:04:39 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/25 15:07:53 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_sort(int *t, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (t[i] > t[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_rev_sort(int *t, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (t[i] < t[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
