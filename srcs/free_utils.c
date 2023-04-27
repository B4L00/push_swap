/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 08:43:13 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/27 09:30:29 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_split(char **sentence, t_stack *s)
{
	int	i;

	i = 0;
	while (sentence[i])
	{
		free(sentence[i]);
		i++;
	}
	free(sentence);
	if (s)
		ft_free_s(s, 1);
}

void	ft_free_s(t_stack *s, int fail)
{
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
	if (fail)
		exit(EXIT_FAILURE);
}

void	ft_free_decision(t_count *c_r, t_count *c_rr, t_count *c_rarrb,
	t_count *c_rrarb)
{
	if (c_r)
		free(c_r);
	if (c_rr)
		free(c_rr);
	if (c_rarrb)
		free(c_rarrb);
	if (c_rrarb)
		free(c_rrarb);
}

void	ft_free_simu_s(t_stack *s_cpy)
{
	free(s_cpy->a);
	free(s_cpy->b);
}

void	ft_free_simu_exit(t_stack *s_cpy, t_stack *real)
{
	ft_free_simu_s(s_cpy);
	ft_free_s(real, 1);
}
