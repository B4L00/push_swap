/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:11:23 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/25 14:30:59 by larmenou         ###   ########.fr       */
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
	tcr = ft_simu_rbra(&s_cpy);
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
	free(s_cpy.a);
	free(s_cpy.b);
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
	tcr = ft_simu_rrbrra(&s_cpy);
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
	free(s_cpy.a);
	free(s_cpy.b);
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
	tcr = ft_simu_rbrra(&s_cpy);
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
	free(s_cpy.a);
	free(s_cpy.b);
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
	tcr = ft_simu_rrbra(&s_cpy);
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
	free(s_cpy.a);
	free(s_cpy.b);
	return (tcr);
}
