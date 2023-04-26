/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:11:23 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/26 14:24:13 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_count	*ft_simulation_rbra(t_stack *s)
{
	t_stack	s_cpy;
	t_count	*tcr;
	int		i;
	int		cptr_i;
	int		cptr;

	s_cpy = ft_init_simu(s);
	tcr = ft_simu_rbra(&s_cpy, s);
	i = 0;
	cptr_i = 0;
	cptr = tcr[i].count_a + tcr[i].count_b;
	while (i < tcr[0].i)
	{
		if (ft_cpt_rr(tcr, i) < cptr)
		{
			cptr = ft_cpt_rr(tcr, i);
			cptr_i = i;
		}
		i++;
	}
	tcr->i = cptr_i;
	tcr->cpt = cptr;
	ft_free_simu_s(&s_cpy);
	return (tcr);
}

t_count	*ft_simulation_rrbrra(t_stack *s)
{
	t_stack	s_cpy;
	t_count	*tcr;
	int		i;
	int		cptr_i;
	int		cptr;

	s_cpy = ft_init_simu(s);
	tcr = ft_simu_rrbrra(&s_cpy, s);
	i = 0;
	cptr_i = 0;
	cptr = tcr[i].count_a + tcr[i].count_b;
	while (i < tcr[0].i)
	{
		if (ft_cpt_rr(tcr, i) < cptr)
		{
			cptr = ft_cpt_rr(tcr, i);
			cptr_i = i;
		}
		i++;
	}
	tcr->i = cptr_i;
	tcr->cpt = cptr;
	ft_free_simu_s(&s_cpy);
	return (tcr);
}

t_count	*ft_simulation_rbrra(t_stack *s)
{
	t_stack	s_cpy;
	t_count	*tcr;
	int		i;
	int		cptr_i;
	int		cptr;

	s_cpy = ft_init_simu(s);
	tcr = ft_simu_rbrra(&s_cpy, s);
	i = 0;
	cptr_i = 0;
	cptr = tcr[i].count_a + tcr[i].count_b;
	while (i < tcr[0].i)
	{
		if (tcr[i].count_a + tcr[i].count_b < cptr)
		{
			cptr = tcr[i].count_a + tcr[i].count_b;
			cptr_i = i;
		}
		i++;
	}
	tcr->i = cptr_i;
	tcr->cpt = cptr;
	ft_free_simu_s(&s_cpy);
	return (tcr);
}

t_count	*ft_simulation_rrbra(t_stack *s)
{
	t_stack	s_cpy;
	t_count	*tcr;
	int		i;
	int		cptr_i;
	int		cptr;

	s_cpy = ft_init_simu(s);
	tcr = ft_simu_rrbra(&s_cpy, s);
	i = 0;
	cptr_i = 0;
	cptr = tcr[i].count_a + tcr[i].count_b;
	while (i < tcr[0].i)
	{
		if (tcr[i].count_a + tcr[i].count_b < cptr)
		{
			cptr = tcr[i].count_a + tcr[i].count_b;
			cptr_i = i;
		}
		i++;
	}
	tcr->i = cptr_i;
	tcr->cpt = cptr;
	ft_free_simu_s(&s_cpy);
	return (tcr);
}
