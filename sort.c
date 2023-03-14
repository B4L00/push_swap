#include "push_swap.h"

void	ft_min(int *t, int len, int *i_min)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	min = t[i];
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (t[j] <= min)
			{
				min = t[j];
				*i_min = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_max(int *t, int len, int *i_max)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = t[i];
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (t[j] >= max)
			{
				max = t[j];
				*i_max = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_end_a(t_stack *s)
{
	int	i_min;
	int	i_max;

	while (!ft_is_sort(s->a, s->len_a))
	{
		ft_min(s->a, s->len_a, &i_min);
		ft_max(s->a, s->len_a, &i_max);
		if (ft_is_rev_sort(s->a, s->len_a))
		{
			ft_ra(s);
			ft_sa(s->a, s->len_a);
		}
		if (i_min == 2 && i_max == 1)
			ft_rra(s);
		if (i_min == 1 && i_max == 2)
			ft_sa(s->a, s->len_a);
		if (i_min == 1 && i_max == 0)
			ft_ra(s);
		if (i_min == 0 && i_max == 1)
		{
			ft_sa(s->a, s->len_a);
			ft_ra(s);
		}
	}
}

void	ft_sort(t_stack *s)
{
	int	i_min;

	if (ft_is_sort(s->a, s->len_a))
		return ;
	while (s->len_a > 3)
	{
		ft_min(s->a, s->len_a, &i_min);
		if (i_min <= s->len_a / 2 && i_min != 0)
			ft_ra(s);
		if (i_min > s->len_a / 2 && i_min != 0)
			ft_rra(s);
		if (i_min == 0)
			ft_pb(s);
	}
	ft_sort_end_a(s);
	while (s->len_b > 0)
		ft_pa(s);
}
