/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_simu_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:15:53 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/25 14:36:58 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_simu_rbra_utils(t_stack *s, t_count *tc, t_count *c)
{
	if ((*s->b < *s->a && *s->b < *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
		|| (*s->b < *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
		|| (*s->b > *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1)
			&& *s->a < *(s->a + 1) && *s->a < *(s->a + s->len_a - 1))
		|| (*s->b < *s->a && *s->b < *(s->a + 1)
			&& *s->b < *(s->a + s->len_a - 1)
			&& *s->a < *(s->a + 1) && *s->a < *(s->a + s->len_a - 1)))
	{
		tc[c->i].count_a = c->count_a;
		tc[c->i].count_b = c->count_b;
		c->i++;
	}
	c->count_b++;
	ft_simu_rb(s);
}

void	ft_simu_rrbrra_utils(t_stack *s, t_count *tc, t_count *c)
{
	if ((*s->b < *s->a && *s->b < *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
		|| (*s->b < *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
		|| (*s->b > *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1)
			&& *s->a < *(s->a + 1) && *s->a < *(s->a + s->len_a - 1))
		|| (*s->b < *s->a && *s->b < *(s->a + 1)
			&& *s->b < *(s->a + s->len_a - 1)
			&& *s->a < *(s->a + 1) && *s->a < *(s->a + s->len_a - 1)))
	{
		tc[c->i].count_a = c->count_a;
		tc[c->i].count_b = c->count_b;
		c->i++;
	}
	c->count_b++;
	ft_simu_rrb(s);
}

void	ft_simu_rbrra_utils(t_stack *s, t_count *tc, t_count *c)
{
	if ((*s->b < *s->a && *s->b < *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
		|| (*s->b < *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
		|| (*s->b > *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1)
			&& *s->a < *(s->a + 1) && *s->a < *(s->a + s->len_a - 1))
		|| (*s->b < *s->a && *s->b < *(s->a + 1)
			&& *s->b < *(s->a + s->len_a - 1)
			&& *s->a < *(s->a + 1) && *s->a < *(s->a + s->len_a - 1)))
	{
		tc[c->i].count_a = c->count_a;
		tc[c->i].count_b = c->count_b;
		c->i++;
	}
	c->count_b++;
	ft_simu_rb(s);
}

void	ft_simu_rrbra_utils(t_stack *s, t_count *tc, t_count *c)
{
	if ((*s->b < *s->a && *s->b < *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
		|| (*s->b < *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1))
		|| (*s->b > *s->a && *s->b > *(s->a + 1)
			&& *s->b > *(s->a + s->len_a - 1)
			&& *s->a < *(s->a + 1) && *s->a < *(s->a + s->len_a - 1))
		|| (*s->b < *s->a && *s->b < *(s->a + 1)
			&& *s->b < *(s->a + s->len_a - 1)
			&& *s->a < *(s->a + 1) && *s->a < *(s->a + s->len_a - 1)))
	{
		tc[c->i].count_a = c->count_a;
		tc[c->i].count_b = c->count_b;
		c->i++;
	}
	c->count_b++;
	ft_simu_rrb(s);
}
