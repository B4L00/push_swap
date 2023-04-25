/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:07:02 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/25 15:52:31 by larmenou         ###   ########.fr       */
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
		{
			free(s);
			return (0);
		}
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

void	ft_free(char **sentence, int len, t_stack *s)
{
	int	i;

	i = 0;
	if (sentence)
	{
		while (i < len)
		{
			free(sentence[i]);
			i++;
		}
		free(sentence);
	}
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
	exit(EXIT_FAILURE);
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
	s->a = NULL;
	s->b = NULL;
	if (!split)
		ft_free(split, s->len_a, s);
	s->len_a = ft_lensplit(split);
	s->a = malloc(sizeof(int) * (s->len_a));
	s->b = malloc(sizeof(int) * (s->len_a));
	if (!s->a || !s->b)
		ft_free(split, s->len_a, s);
	while (i < s->len_a)
	{
		s->a[i] = ft_atoi((const char *)split[i]);
		i++;
	}
	if (!ft_check(s->a, split, s->len_a))
	{	
		ft_printf("Error\n");
		ft_free(split, s->len_a, s);
	}
}

void	main_suite(t_stack *s, char **argv, int argc, char **split)
{
	int	i;

	i = 0;
	s->len_a = argc - 1;
	s->a = malloc(sizeof(int) * (s->len_a));
	s->b = malloc(sizeof(int) * (s->len_a));
	if (!s->a || !s->b)
		ft_free(split, s->len_a, s);
	while (i < s->len_a)
	{
		s->a[i] = ft_atoi((const char *)argv[i + 1]);
		s->b[i] = 0;
		i++;
	}
	if (!ft_check(s->a, argv + 1, s->len_a))
	{
		ft_printf("Error\n");
		ft_free(split, s->len_a, s);
	}
}
