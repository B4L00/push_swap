/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:45 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/25 13:27:14 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_r_decision(t_stack *s, t_count *c_r)
{
	while (c_r[c_r->i].count_a > 0 && c_r[c_r->i].count_b > 0)
	{
		ft_rr(s);
		c_r[c_r->i].count_a--;
		c_r[c_r->i].count_b--;
	}
	while (c_r[c_r->i].count_a > 0)
	{
		ft_ra(s);
		c_r[c_r->i].count_a--;
	}
	while (c_r[c_r->i].count_b > 0)
	{
		ft_rb(s);
		c_r[c_r->i].count_b--;
	}
}

void	ft_rr_decision(t_stack *s, t_count *c_rr)
{
	while (c_rr[c_rr->i].count_a > 0 && c_rr[c_rr->i].count_b > 0)
	{
		ft_rrr(s);
		c_rr[c_rr->i].count_a--;
		c_rr[c_rr->i].count_b--;
	}
	while (c_rr[c_rr->i].count_a > 0)
	{
		ft_rra(s);
		c_rr[c_rr->i].count_a--;
	}
	while (c_rr[c_rr->i].count_b > 0)
	{
		ft_rrb(s);
		c_rr[c_rr->i].count_b--;
	}
}

void	ft_rarrb_decision(t_stack *s, t_count *c_rarrb)
{
	while (c_rarrb[c_rarrb->i].count_a > 0)
	{
		ft_ra(s);
		c_rarrb[c_rarrb->i].count_a--;
	}
	while (c_rarrb[c_rarrb->i].count_b > 0)
	{
		ft_rrb(s);
		c_rarrb[c_rarrb->i].count_b--;
	}
}

void	ft_rrarb_decision(t_stack *s, t_count *c_rrarb)
{
	while (c_rrarb[c_rrarb->i].count_a > 0)
	{
		ft_rra(s);
		c_rrarb[c_rrarb->i].count_a--;
	}
	while (c_rrarb[c_rrarb->i].count_b > 0)
	{
		ft_rb(s);
		c_rrarb[c_rrarb->i].count_b--;
	}
}
