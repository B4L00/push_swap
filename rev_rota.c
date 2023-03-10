#include "push_swap.h"

void	ft_rra(t_stack *s)
{
	int	i;
	int	tmp;

	i = s->len_a - 1;
	tmp = s->a[i];
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[i] = tmp;
	printf("rra\n");
}

void	ft_rrb(t_stack *s)
{
	int	i;
	int	tmp;

	i = s->len_b - 1;
	tmp = s->b[i];
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[i] = tmp;
	printf("rrb\n");
}

void	ft_rrr(t_stack *s)
{
	ft_rra(s);
	ft_rrb(s);
	printf("rrr\n");
}