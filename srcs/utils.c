/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:07:02 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/24 15:47:14 by larmenou         ###   ########.fr       */
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

char	**ft_free(char **sentence, int len)
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
/* 	free(s->a);
	free(s->b); */
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

void	main_argc2(t_stack *s, char **argv, char **split)
{
	int	i;

	i = 0;
	split = ft_split(argv[1], ' ');
	s->len_a = ft_lensplit(split);
	s->a = malloc(sizeof(int) * (s->len_a));
	s->b = malloc(sizeof(int) * (s->len_a));
	if (!s->a || !s->b)
	{
		ft_free(split, s->len_a);
		exit(EXIT_FAILURE);
	}
	while (i < s->len_a)
	{
		s->a[i] = ft_atoi((const char *)split[i]);
		i++;
	}
	if (!ft_check(s->a, split, s->len_a))
	{	
		ft_printf("Error\n");
		ft_free(split, s->len_a);
		exit(EXIT_FAILURE);
	}
	if (ft_is_sort(s->a, s->len_a))
		return ;
	else if (s->len_a == 3)
	{
		ft_sort_end_a(s);
		free(s->a);
		free(s->b);
		return ;
	}
}

void	main_suite(t_stack *s, char **argv, int argc, char **split)
{
	int	i;

	i = 0;
	s->len_a = argc - 1;
	s->a = malloc(sizeof(int) * (s->len_a));
	s->b = malloc(sizeof(int) * (s->len_a));
	while (i < s->len_a)
	{
		s->a[i] = ft_atoi((const char *)argv[i + 1]);
		s->b[i] = 0;
		i++;
	}
	if (!ft_check(s->a, argv + 1, s->len_a))
	{
		ft_printf("Error\n");
		ft_free(split, s->len_a);
		exit(EXIT_FAILURE);
	}
	if (ft_is_sort(s->a, s->len_a))
		return ;
	else if (s->len_a == 3)
	{
		ft_sort_end_a(s);
		free(s->a);
		free(s->b);
		return ;
	}
}
