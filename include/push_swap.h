/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:04:54 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/12 10:35:31 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../srcs/libft/srcs/libft.h"
# include "../srcs/libft/srcs/ft_printf/include/ft_printf.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}	t_stack;

/* swap_push.c */

void	ft_sa(int *a, int len);
void	ft_sb(int *b, int len);
void	ft_ss(t_stack *s);
void	ft_pa(t_stack *s);
void	ft_pb(t_stack *s);

/* rotate.c */

void	ft_ra(t_stack *s);
void	ft_rb(t_stack *s);
void	ft_rr(t_stack *s);

/* rev_rota.c */

void	ft_rra(t_stack *s);
void	ft_rrb(t_stack *s);

/* is_sort.c */

int		ft_is_sort(int *t, int len);
int		ft_is_rev_sort(int *t, int len);

/* sort.c */

void	ft_sort(t_stack *s);
void	ft_min(int *t, int len, int *i_min);
void	ft_max(int *t, int len, int *i_max);
void	ft_sort_end_a(t_stack *s);

/* pivot.c */

int	ft_pivot(t_stack *s, int cut);

/* pre_sort.c */

void	ft_pre_sort(t_stack *s, int pivot);
void	ft_final_pre_sort(t_stack *s);

void	ft_quick_sort(t_stack *s);

#endif
