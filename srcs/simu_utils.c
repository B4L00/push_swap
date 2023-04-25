/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:49:21 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/25 13:12:18 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_simu(t_stack *s_cpy, t_count *c)
{
	free(c);
	free(s_cpy->a);
	free(s_cpy->b);
}

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
	if (!s_cpy.a)
	{
		free(s_cpy.b);
		exit(EXIT_FAILURE);
	}
	if (!s_cpy.b)
	{
		free(s_cpy.a);
		exit(EXIT_FAILURE);
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
