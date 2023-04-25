/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota_simu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:05:53 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/25 09:31:52 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_simu_ra(t_stack *s_cpy)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s_cpy->a[i];
	while (i + 1 < s_cpy->len_a)
	{
		s_cpy->a[i] = s_cpy->a[i + 1];
		i++;
	}
	s_cpy->a[i] = tmp;
}

void	ft_simu_rb(t_stack *s_cpy)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s_cpy->b[i];
	while (i + 1 < s_cpy->len_b)
	{
		s_cpy->b[i] = s_cpy->b[i + 1];
		i++;
	}
	s_cpy->b[i] = tmp;
}

void	ft_simu_rra(t_stack *s_cpy)
{
	int	i;
	int	tmp;

	i = s_cpy->len_a - 1;
	tmp = s_cpy->a[i];
	while (i > 0)
	{
		s_cpy->a[i] = s_cpy->a[i - 1];
		i--;
	}
	s_cpy->a[i] = tmp;
}

void	ft_simu_rrb(t_stack *s_cpy)
{
	int	i;
	int	tmp;

	i = s_cpy->len_b - 1;
	tmp = s_cpy->b[i];
	while (i > 0)
	{
		s_cpy->b[i] = s_cpy->b[i - 1];
		i--;
	}
	s_cpy->b[i] = tmp;
}
