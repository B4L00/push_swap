#include "push_swap.h"
#include <stdio.h>

int	ft_check(int *a, char **argv, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		//printf("%s\n", argv[i]);
		if (ft_strncmp(ft_itoa(a[i]), argv[i], ft_strlen(argv[i])))
			return (0);
		j = i + 1;
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

static char	**ft_free(char **sentence)
{
	int	i;

	i = 0;
	while (sentence[i])
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
	t_stack s;
	char	**split;
	int		i;

	i = 0;
	s.a = malloc(sizeof(int) * (argc - 1));
	s.b = malloc(sizeof(int) * (argc - 1));
	s.len_b = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		//printf("argc == 2\n");
		split = ft_split(argv[1], ' ');
		s.len_a = ft_lensplit(split);
		while (i < s.len_a)
		{
			//printf("%s\n", split[i]);
			s.a[i] = ft_atoi((const char *)split[i]);
			i++;
		}
		//printf("%s\n", split[0]);
		if (!ft_check(s.a, split, s.len_a))
			printf("Error\n");
	}
	else
	{
		s.len_a = argc - 1;
		//printf("argc > 2\n");
		while (i < s.len_a)
		{
			s.a[i] = ft_atoi((const char *)argv[i + 1]);
			i++;
		}
		if (!ft_check(s.a, argv + 1, s.len_a))
			printf("Error\n");
	}
	//printf("OK\n");
	//ft_free(split);
	ft_sort(&s);
	//printf("Trier a ? : %d\n", ft_is_sort(s.a, s.len_a));
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
	return (0);
}