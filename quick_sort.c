void	ft_sort_b(t_stack *s)
{
	int	i_min;
	int	i_max;

	while (!ft_is_rev_sort(s->b, s->len_b))
	{
		i_min = ft_min(s->a, s->len_a, &i_min);
		i_max = ft_max(s->b, s->len_b, &i_max);
		if (ft_is_sort(s->b, s->len_b))
		{
			ft_sb(s->b, s->len_b);
			ft_rrb(s);
		}
		if (i_max == 0 && i_min == 1)
		{	
			ft_sb(s->b, s->len_b);
			ft_rb(s);
		}
		if (i_max == 2 && i_min == 1)
			ft_rrb(s);
		if (i_max == 1 && i_min == 2)
			ft_sb(s->b, s->len_b);
		if (i_max == 1 && i_min == 0)
			ft_rb(s);
	}
}

void	ft_quick_sort(t_stack *s)
{
	int	pivot;
	int	i;

	if (ft_is_sort(s->a, s->len_a)
		return ;
	pivot = s->a[0];
	i = 0;
	while (ft_is_sort(s->a, s->len_a))
	{
		if (i < 3 && s[0] <= pivot)
		{
			ft_pb(s);
			i++;
		}
		if (i == 3)
		{
			ft_sort_b(s);
			while (i >= 0)
			{
				ft_pa(s);
				ft_ra(s);
				i--;
			}
		}
		else
			ft_ra(s);
	}
}
