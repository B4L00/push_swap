#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int *a;
	int *b;
	int len_a;
	int len_b;
}	t_stack;

void	ft_sa(int *a, int len);
void	ft_sb(int *b, int len);
void	ft_ss(t_stack *s);
void	ft_pa(t_stack *s);
void	ft_pb(t_stack *s);
void	ft_ra(t_stack *s);
void	ft_rb(t_stack *s);
void	ft_rr(t_stack *s);
void	ft_rra(t_stack *s);
void	ft_rrb(t_stack *s);
int	ft_is_sort(int *t, int len);
int	ft_is_rev_sort(int *t, int len);
void	ft_sort(t_stack *s);
void	ft_min(int *t, int len, int *i_min);
void	ft_max(int *t, int len, int *i_max);
void	ft_sort_end_a(t_stack *s);
void	ft_quick_sort(t_stack *s);

#endif
