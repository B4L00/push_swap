/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_simu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:42:24 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/26 14:35:25 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_count	*ft_simu_rbra(t_stack *s, t_stack *real)
{
	int		i;
	int		j;
	t_count	*tc;
	t_count	c;

	tc = malloc(sizeof(t_count) * (s->len_a * s->len_b));
	if (!tc)
		ft_free_simu_exit(s, real);
	j = 0;
	c.i = 0;
	c.count_a = 0;
	while (j < s->len_a)
	{
		i = 0;
		c.count_b = 0;
		while (i++ < s->len_b)
			ft_simu_rbra_utils(s, tc, &c);
		c.count_a++;
		ft_simu_ra(s);
		j++;
	}
	tc[0].i = c.i;
	return (tc);
}

t_count	*ft_simu_rrbrra(t_stack *s, t_stack *real)
{
	int		i;
	int		j;
	t_count	*tc;
	t_count	c;

	tc = malloc(sizeof(t_count) * (s->len_a * s->len_b));
	if (!tc)
		ft_free_simu_exit(s, real);
	j = 0;
	c.i = 0;
	c.count_a = 0;
	while (j < s->len_a)
	{
		i = 0;
		c.count_b = 0;
		while (i++ < s->len_b)
			ft_simu_rrbrra_utils(s, tc, &c);
		c.count_a++;
		ft_simu_rra(s);
		j++;
	}
	tc[0].i = c.i;
	return (tc);
}

t_count	*ft_simu_rbrra(t_stack *s, t_stack *real)
{
	int		i;
	int		j;
	t_count	*tc;
	t_count	c;

	tc = malloc(sizeof(t_count) * (s->len_a * s->len_b));
	if (!tc)
		ft_free_simu_exit(s, real);
	j = 0;
	c.i = 0;
	c.count_a = 0;
	while (j < s->len_a)
	{
		i = 0;
		c.count_b = 0;
		while (i++ < s->len_b)
			ft_simu_rbrra_utils(s, tc, &c);
		c.count_a++;
		ft_simu_rra(s);
		j++;
	}
	tc[0].i = c.i;
	return (tc);
}

t_count	*ft_simu_rrbra(t_stack *s, t_stack *real)
{
	int		i;
	int		j;
	t_count	*tc;
	t_count	c;

	tc = malloc(sizeof(t_count) * (s->len_a * s->len_b));
	if (!tc)
		ft_free_simu_exit(s, real);
	j = 0;
	c.i = 0;
	c.count_a = 0;
	while (j < s->len_a)
	{
		i = 0;
		c.count_b = 0;
		while (i++ < s->len_b)
			ft_simu_rrbra_utils(s, tc, &c);
		c.count_a++;
		ft_simu_ra(s);
		j++;
	}
	tc[0].i = c.i;
	return (tc);
}
