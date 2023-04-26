/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:31:44 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/26 11:49:58 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_decision_suite(t_stack *s, t_count **tc)
{
	if ((tc[0][tc[0]->i].count_a == 0 && tc[0][tc[0]->i].count_b == 0)
		|| (tc[1][tc[1]->i].count_a == 0 && tc[1][tc[1]->i].count_b == 0)
		|| (tc[3][tc[3]->i].count_a == 0
			&& tc[3][tc[3]->i].count_b == 0)
		|| (tc[2][tc[2]->i].count_a == 0
			&& tc[2][tc[2]->i].count_b == 0))
		ft_pa(s);
}

void	ft_decision(t_stack *s)
{
	t_count	*tc[4];

	tc[0] = ft_simulation_rbra(s);
	tc[1] = ft_simulation_rrbrra(s);
	tc[2] = ft_simulation_rrbra(s);
	tc[3] = ft_simulation_rbrra(s);
	if (!tc[0] || !tc[1] || !tc[2] || !tc[3])
	{
		ft_free_decision(tc[0], tc[1], tc[2], tc[3]);
		ft_free_s(s, 1);
	}
	if (tc[0]->cpt <= tc[1]->cpt && tc[0]->cpt <= tc[2]->cpt
		&& tc[0]->cpt <= tc[3]->cpt)
		ft_r_decision(s, tc[0]);
	else if (tc[1]->cpt <= tc[0]->cpt && tc[1]->cpt <= tc[2]->cpt
		&& tc[1]->cpt <= tc[3]->cpt)
		ft_rr_decision(s, tc[1]);
	else if (tc[2]->cpt <= tc[0]->cpt && tc[2]->cpt <= tc[1]->cpt
		&& tc[2]->cpt <= tc[3]->cpt)
		ft_rarrb_decision(s, tc[2]);
	else if (tc[3]->cpt <= tc[0]->cpt && tc[3]->cpt <= tc[1]->cpt
		&& tc[3]->cpt <= tc[2]->cpt)
		ft_rrarb_decision(s, tc[3]);
	ft_decision_suite(s, tc);
	ft_free_decision(tc[0], tc[1], tc[2], tc[3]);
}
