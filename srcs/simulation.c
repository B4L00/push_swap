/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:31:44 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/24 17:17:11 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_count	*ft_realloc(t_count *tc, t_count *c)
{
	t_count	*dest;
	int		i;

	if (!tc)
		return (NULL);
	i = 0;
	dest = malloc(sizeof(t_count) * (c->i + 1));
	if (!dest)
		return (NULL);
	while (i < c->i)
	{
		dest[i].count_a = tc[i].count_a;
		dest[i].count_b = tc[i].count_b;
		i++;
	}
	tc[i].count_a = c->count_a;
	tc[i].count_b = c->count_b;
	free(tc);
	return (dest);
}

void	ft_free_simu(t_stack *s_cpy, t_count *c)
{
	free(c);
	free(s_cpy->a);
	free(s_cpy->b);
}

t_stack	ft_init_simu(t_stack *s)
{
	int	i;
	t_stack s_cpy;

	i = 0;
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
	if (!s)
	{
		free(s_cpy.a);
		free(s_cpy.b);
		exit(EXIT_FAILURE);
	}
	while (i < s->len_a)
	{
		s_cpy.a[i] = s->a[i];
		i++;
	}
	i = 0;
	while (i < s->len_b)
	{
		s_cpy.b[i] = s->b[i];
		i++;
	}
	s_cpy.len_a = s->len_a;
	s_cpy.len_b = s->len_b;
	return (s_cpy);
}

t_count	*ft_simu_rbra(t_stack *s)
{
	int		i;
	int		j;
	t_count	*tc;
	t_count	c;

	tc = malloc(sizeof(t_count) * (s->len_a * s->len_b));
	j = 0;
	c.i = 0;
	c.count_a = 0;
	while (j < s->len_a)
	{
		i = 0;
		c.count_b = 0;
		while (i < s->len_b)
		{
/* 			if ((*s->b > *s->a && *s->b < *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b > *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (ft_is_max(s->a, s->len_a, *s->b)
					&& !ft_is_min(s->a, s->len_a, *s->a))
				|| (ft_is_min(s->a, s->len_a, *s->b)
					&& !ft_is_min(s->a, s->len_a, *s->a))
				|| (*s->b < *s->a && *s->b < *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b > *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b < *s->a && *s->b > *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b < *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))) */
			if ((*s->b < *s->a && *s->b < *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (*s->b < *s->a && *s->b > *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (ft_is_max(s->a, s->len_a, *s->b)
					&& ft_is_min(s->a, s->len_a, *s->a))
				|| (ft_is_min(s->a, s->len_a, *s->b)
					&& ft_is_min(s->a, s->len_a, *s->a)))
			{
				tc[c.i].count_a = c.count_a;
				tc[c.i].count_b = c.count_b;
				/* tc = ft_realloc(tc, &c);
				if (!tc)
					return (NULL); */
				c.i++;
			}
			c.count_b++;
			ft_simu_rb(s);
			i++;
		}
		c.count_a++;
		ft_simu_ra(s);
		j++;
	}
/*  	i = 0;
	while (i < c.i)
	{
		printf("i = %d, count_a : %d, count_b : %d\n", i, tc[i].count_a, tc[i].count_b);
		i++;
	} */
	tc[0].i = c.i;
	return (tc);
}

t_count	*ft_simu_rrbrra(t_stack *s)
{
	int		i;
	int		j;
	t_count	*tc;
	t_count	c;

	tc = malloc(sizeof(t_count) * (s->len_a * s->len_b));
	j = 0;
	c.i = 0;
	c.count_a = 0;
	while (j < s->len_a)
	{
		i = 0;
		c.count_b = 0;
		while (i < s->len_b)
		{
			/* if ((*s->b > *s->a && *s->b < *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b > *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (ft_is_max(s->a, s->len_a, *s->b)
					&& !ft_is_min(s->a, s->len_a, *s->a))
				|| (ft_is_min(s->a, s->len_a, *s->b)
					&& !ft_is_min(s->a, s->len_a, *s->a))
				|| (*s->b < *s->a && *s->b < *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b > *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b < *s->a && *s->b > *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b < *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))) */
			if ((*s->b < *s->a && *s->b < *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (*s->b < *s->a && *s->b > *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (ft_is_max(s->a, s->len_a, *s->b)
					&& ft_is_min(s->a, s->len_a, *s->a))
				|| (ft_is_min(s->a, s->len_a, *s->b)
					&& ft_is_min(s->a, s->len_a, *s->a)))
			{
				tc[c.i].count_a = c.count_a;
				tc[c.i].count_b = c.count_b;
				//tc = ft_realloc(tc, &c);
				c.i++;
			}
			c.count_b++;
			ft_simu_rrb(s);
			i++;
		}
		c.count_a++;
		ft_simu_rra(s);
		j++;
	}
/* 	i = 0;
	while (i < c.i)
	{
		printf("i = %d, count_a : %d, count_b : %d\n", i, tc[i].count_a, tc[i].count_b);
		i++;
	} */
	tc[0].i = c.i;
	return (tc);
}

t_count	*ft_simu_rbrra(t_stack *s)
{
	int		i;
	int		j;
	t_count	*tc;
	t_count	c;

	tc = malloc(sizeof(t_count) * (s->len_a * s->len_b));
	j = 0;
	c.i = 0;
	c.count_a = 0;
	while (j < s->len_a)
	{
		i = 0;
		c.count_b = 0;
		while (i < s->len_b)
		{
			/* if ((*s->b > *s->a && *s->b < *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b > *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (ft_is_max(s->a, s->len_a, *s->b)
					&& !ft_is_min(s->a, s->len_a, *s->a))
				|| (ft_is_min(s->a, s->len_a, *s->b)
					&& !ft_is_min(s->a, s->len_a, *s->a))
				|| (*s->b < *s->a && *s->b < *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b > *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b < *s->a && *s->b > *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b < *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))) */
			if ((*s->b < *s->a && *s->b < *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (*s->b < *s->a && *s->b > *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (ft_is_max(s->a, s->len_a, *s->b)
					&& ft_is_min(s->a, s->len_a, *s->a))
				|| (ft_is_min(s->a, s->len_a, *s->b)
					&& ft_is_min(s->a, s->len_a, *s->a)))
			{
				tc[c.i].count_a = c.count_a;
				tc[c.i].count_b = c.count_b;
				//tc = ft_realloc(tc, &c);
				c.i++;
			}
			c.count_b++;
			ft_simu_rb(s);
			i++;
		}
		c.count_a++;
		ft_simu_rra(s);
		j++;
	}
/* 	i = 0;
	while (i < c.i)
	{
		printf("i = %d, count_a : %d, count_b : %d\n", i, tc[i].count_a, tc[i].count_b);
		i++;
	} */
	tc[0].i = c.i;
	return (tc);
}

t_count	*ft_simu_rrbra(t_stack *s)
{
	int		i;
	int		j;
	t_count	*tc;
	t_count	c;

	tc = malloc(sizeof(t_count) * (s->len_a * s->len_b));
	j = 0;
	c.i = 0;
	c.count_a = 0;
	while (j < s->len_a)
	{
		i = 0;
		c.count_b = 0;
		while (i < s->len_b)
		{
			/* if ((*s->b > *s->a && *s->b < *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b > *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (ft_is_max(s->a, s->len_a, *s->b)
					&& !ft_is_min(s->a, s->len_a, *s->a))
				|| (ft_is_min(s->a, s->len_a, *s->b)
					&& !ft_is_min(s->a, s->len_a, *s->a))
				|| (*s->b < *s->a && *s->b < *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b > *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b < *s->a && *s->b > *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))
				|| (*s->b > *s->a && *s->b < *(s->a + 1)
					&& *s->b < *(s->a + s->len_a - 1))) */
			if ((*s->b < *s->a && *s->b < *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (*s->b < *s->a && *s->b > *(s->a + 1)
					&& *s->b > *(s->a + s->len_a - 1))
				|| (ft_is_max(s->a, s->len_a, *s->b)
					&& ft_is_min(s->a, s->len_a, *s->a))
				|| (ft_is_min(s->a, s->len_a, *s->b)
					&& ft_is_min(s->a, s->len_a, *s->a)))
			{
				tc[c.i].count_a = c.count_a;
				tc[c.i].count_b = c.count_b;
				//tc = ft_realloc(tc, &c);
				c.i++;
			}
			c.count_b++;
			ft_simu_rrb(s);
			i++;
		}
		c.count_a++;
		ft_simu_ra(s);
		j++;
	}
/* 	i = 0;
	while (i < c.i)
	{
		printf("i = %d, count_a : %d, count_b : %d\n", i, tc[i].count_a, tc[i].count_b);
		i++;
	} */
	tc[0].i = c.i;
	return (tc);
}

int	ft_cpt_rr(t_count *tcr, int i)
{
	int	cpt;
	int count_a_tmp;
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

void	ft_decision(t_stack *s)
{
	t_count	*c_r;
	t_count	*c_rr;
	t_count	*c_rarrb;
	t_count	*c_rrarb;
	
	c_r = ft_simulation_rbra(s);
	c_rr = ft_simulation_rrbrra(s);
	c_rarrb = ft_simulation_rrbra(s);
	c_rrarb = ft_simulation_rbrra(s);

/* 	int i = 0;
	while (i < s->len_a)
	{
		printf("%d\n", s->a[i]);
		i++;
	}
	printf("\n\n");
	i = 0;
	while (i < s->len_b)
	{
		printf("%d\n", s->b[i]);
		i++;
	} */

	//printf("%d, %d, %d, %d\n", c_r->cpt, c_rr->cpt, c_rarrb->cpt, c_rrarb->cpt);
	printf("%d\n", s->len_a);
	if (c_r->cpt <= c_rr->cpt && c_r->cpt <= c_rarrb->cpt
		&& c_r->cpt <= c_rrarb->cpt)
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
	else if (c_rr->cpt <= c_r->cpt && c_rr->cpt <= c_rarrb->cpt
		&& c_rr->cpt <= c_rrarb->cpt)
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
	else if (c_rarrb->cpt <= c_r->cpt && c_rarrb->cpt <= c_rr->cpt
		&& c_rarrb->cpt <= c_rrarb->cpt)
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
	else if (c_rrarb->cpt <= c_r->cpt && c_rrarb->cpt <= c_rr->cpt
		&& c_rrarb->cpt <= c_rarrb->cpt)
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
	if ((c_r[c_r->i].count_a == 0 && c_r[c_r->i].count_b == 0)
		|| (c_rr[c_rr->i].count_a == 0 && c_rr[c_rr->i].count_b == 0)
		|| (c_rrarb[c_rrarb->i].count_a == 0
			&& c_rrarb[c_rrarb->i].count_b == 0)
		|| (c_rarrb[c_rarrb->i].count_a == 0
			&& c_rarrb[c_rarrb->i].count_b == 0))
		ft_pa(s);
	free(c_r);
	free(c_rr);
	free(c_rarrb);
	free(c_rrarb);
}

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
