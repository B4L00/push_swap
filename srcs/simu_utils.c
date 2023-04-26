/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:49:21 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/26 14:34:40 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	ft_scpy(t_stack *old, t_stack new)
{
	int	i;

	i = 0;
	while (i < old->len_a)
	{
		new.a[i] = old->a[i];
		i++;
	}
	i = 0;
	while (i < old->len_b)
	{
		new.b[i] = old->b[i];
		i++;
	}
	new.len_a = old->len_a;
	new.len_b = old->len_b;
	return (new);
}

t_stack	ft_init_simu(t_stack *s)
{
	t_stack	s_cpy;

	if (!s)
		exit(EXIT_FAILURE);
	s_cpy.a = malloc(sizeof(int) * s->len_a);
	s_cpy.b = malloc(sizeof(int) * s->len_b);
	if (!s_cpy.a || !s_cpy.b)
	{
		ft_free_s(&s_cpy, 0);
		ft_free_s(s, 1);
	}
	s_cpy = ft_scpy(s, s_cpy);
	return (s_cpy);
}

int	ft_cpt_rr(t_count *tcr, int i)
{
	int	cpt;
	int	count_a_tmp;
	int	count_b_tmp;

	cpt = 0;
	count_a_tmp = tcr[i].count_a;
	count_b_tmp = tcr[i].count_b;
	while (tcr[i].count_a > 0 && tcr[i].count_b > 0)
	{
		cpt++;
		tcr[i].count_a--;
		tcr[i].count_b--;
	}
	if (tcr[i].count_a > 0)
		cpt += tcr[i].count_a;
	else
		cpt += tcr[i].count_b;
	tcr[i].count_a = count_a_tmp;
	tcr[i].count_b = count_b_tmp;
	return (cpt);
}
