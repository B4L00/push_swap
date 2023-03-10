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

int	ft_max(int *t, int len)
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
				max = t[j];
			j++;
		}
		i++;
	}
	return (max);
}

void	ft_sort(t_stack *s)
{
	int i;
	int	i_min;

	if (ft_is_sort(s->a, s->len_a))
		return ;
	i = s->len_a / 2;
	while (s->len_a > 3)
	{
		ft_min(s->a, s->len_a, &i_min);
		if (i_min < s->len_a / 2 && i_min != 0)
			ft_ra(s);
		if (i_min >= s->len_a / 2 && i_min != 0)
			ft_rra(s);
		if (i_min == 0)
			ft_pb(s);
		if (s->len_a == 3)
		{
			if (!ft_is_sort(s->a, s->len_a) && ft_max(s->a, s->len_a) == s->a[s->len_a])
			{
				ft_sa(s->a, s->len_a);
				break ;
			}
			if (!ft_is_sort(s->a, s->len_a))
			{
				if (ft_is_rev_sort(s->a, s->len_a))
				{
					ft_ra(s);
					ft_sa(s->a, s->len_a);
				}
				else
					ft_ra(s);
			}
		}
	}
	while (s->len_b > 0)
		ft_pa(s);
}
