/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:04:48 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/26 09:39:21 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	s;
	char	**split;

	split = NULL;
	s.len_b = 0;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		main_argc2(&s, argv, split);
	else
		main_suite(&s, argv, argc);
	if (ft_is_sort(s.a, s.len_a))
	{
		ft_free_s(&s, 0);
		return (0);
	}
	if (s.len_a == 3)
		ft_sort_end_a(&s);
	else if (s.len_a < 6)
		ft_sort_5(&s);
	else
		ft_main_sort(&s);
	ft_free_s(&s, 0);
	return (0);
}
