#include "push_swap.h"

void	ft_ra(t_stack *s)
{
	int i;
	int tmp;

	i = 0;
	tmp = s->a[i];
	while (i + 1 < s->len_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i] = tmp;
	printf("ra\n");
}

void	ft_rb(t_stack *s)
{
	int i;
	int tmp;

	i = 0;
	tmp = s->b[i];
	while (i + 1 < s->len_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i] = tmp;
	printf("rb\n");
}

void	ft_rr(t_stack *s)
{
	ft_ra(s);
	ft_rb(s);
	printf("rr\n");
}