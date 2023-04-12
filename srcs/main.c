/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:04:48 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/12 14:09:36 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check(int *a, char **argv, int len)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (i < len)
	{
		s = ft_itoa(a[i]);
		if (ft_strncmp(s, argv[i], ft_strlen(argv[i])))
			return (0);
		j = i + 1;
		free(s);
		while (j < len)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static char	**ft_free(char **sentence, int len)
{
	int	i;

	i = 0;
	if (!sentence)
		return (NULL);
	while (i < len)
	{
		free(sentence[i]);
		i++;
	}
	free(sentence);
	return (NULL);
}

int	ft_lensplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	s;
	char	**split;
	int		i;

	i = 0;
	split = NULL;
	s.a = malloc(sizeof(int) * (argc - 1));
	s.b = malloc(sizeof(int) * (argc - 1));
	s.len_b = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		s.len_a = ft_lensplit(split);
		while (i < s.len_a)
		{
			s.a[i] = ft_atoi((const char *)split[i]);
			i++;
		}
		if (!ft_check(s.a, split, s.len_a))
		{	
			ft_printf("Error\n");
			free(s.a);
			free(s.b);
			ft_free(split, s.len_a);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		s.len_a = argc - 1;
		while (i < s.len_a)
		{
			s.a[i] = ft_atoi((const char *)argv[i + 1]);
			i++;
		}
		if (!ft_check(s.a, argv + 1, s.len_a))
		{
			ft_printf("Error\n");
			free(s.a);
			free(s.b);
			ft_free(split, s.len_a);
			exit(EXIT_FAILURE);
		}
	}

	ft_free(split, s.len_a);

/* 14 18 25 28 2 17 6 27 29 3 10 20 4 8 26 7 22 21 16 15 30 19 13 11 12 24 5 23 9 1 */

	int pivot;
	
	pivot = ft_pivot(&s, 2);
	ft_pre_sort(&s, pivot);
	ft_final_pre_sort(&s);
	//ft_sort(&s);

	i = 0;
	while (i < s.len_a)
	{
		printf("%d\n", s.a[i]);
		i++;
	}
	printf("\n\n");
	i = 0;
	while (i < s.len_b)
	{
		printf("%d\n", s.b[i]);
		i++;
	}

	
/* 	pivot = ft_pivot(&s, 3);
	ft_pre_sort(&s, pivot);
	pivot = ft_pivot(&s, 2);
	ft_pre_sort(&s, pivot); */
	






	
	/*
	if (s.len_a == 3)
		ft_sort_end_a(&s);
	else
		ft_sort(&s); */
	// ft_printf("Trier a ? : %d\n", ft_is_sort(s.a, s.len_a));
	//printf("Trier b ? : %d\n\n", ft_is_rev_sort(s.b, s.len_b));

	/*	
	i = 0;
	while (i < s.len_a)
	{
		printf("%d\n", s.a[i]);
		i++;
	}
	*/

	free(s.a);
	free(s.b);
	exit(EXIT_SUCCESS);
}
