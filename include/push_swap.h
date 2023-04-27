/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:04:54 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/27 13:40:40 by larmenou         ###   ########.fr       */
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
	int	pivot;
}	t_stack;

typedef struct s_count
{
	int	count_a;
	int	count_b;
	int	i;
	int	cpt;
}	t_count;

typedef struct s_simu
{
	int	rarb;
	int	i_rarb;
	int	rrarrb;
	int	i_rrarrb;
	int	rarrb;
	int	i_rarrb;
	int	rrarb;
	int	i_rrarb;
}	t_simu;

/* utils.c */

int		ft_check(int *a, char **argv, int len);
int		ft_lensplit(char **split);
void	main_argc2(t_stack *s, char **argv, char **split);
void	main_suite(t_stack *s, char **argv, int argc);

/* check_utils.c */

int		ft_check_utils(char *s, char **argv, int i);

/* free_utils.c */

void	ft_free_split(char **sentence, t_stack *s);
void	ft_free_s(t_stack *s, int fail);
void	ft_free_decision(t_count *c_r, t_count *c_rr, t_count *c_rarrb,
			t_count *c_rrarb);
void	ft_free_simu_s(t_stack *s_cpy);
void	ft_free_simu_exit(t_stack *s_cpy, t_stack *real);

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
void	ft_rrr(t_stack *s);

/* is_sort.c */

int		ft_is_sort(int *t, int len);
int		ft_is_rev_sort(int *t, int len);

/* min_max.c */

int		ft_is_min(int *t, int len, int n);
int		ft_is_max(int *t, int len, int n);
int		ft_find_min(t_stack *s, int *i_min);

/* sort.c */

void	ft_sort(t_stack *s);
void	ft_sort_end_a(t_stack *s);
void	ft_sort_5(t_stack *s);
void	ft_main_sort(t_stack *s);

/* pivot.c */

int		ft_pivot(t_stack *s, int cut);

/* pre_sort.c */

void	ft_pre_sort(t_stack *s, int pivot);
void	ft_final_pre_sort(t_stack *s);

/* simulation.c */

t_count	*ft_simulation_rbra(t_stack *s);
t_count	*ft_simulation_rrbrra(t_stack *s);
t_count	*ft_simulation_rbrra(t_stack *s);
t_count	*ft_simulation_rrbra(t_stack *s);

/* rota_simu.c */

void	ft_simu_rb(t_stack *s_cpy);
void	ft_simu_ra(t_stack *s_cpy);
void	ft_simu_rra(t_stack *s_cpy);
void	ft_simu_rrb(t_stack *s_cpy);

/* mic_simu_utils.c */

void	ft_simu_rbra_utils(t_stack *s, t_count *tc, t_count *c);
void	ft_simu_rrbrra_utils(t_stack *s, t_count *tc, t_count *c);
void	ft_simu_rbrra_utils(t_stack *s, t_count *tc, t_count *c);
void	ft_simu_rrbra_utils(t_stack *s, t_count *tc, t_count *c);

/* mix_simu.c */

t_count	*ft_simu_rbra(t_stack *s, t_stack *real);
t_count	*ft_simu_rrbrra(t_stack *s, t_stack *real);
t_count	*ft_simu_rbrra(t_stack *s, t_stack *real);
t_count	*ft_simu_rrbra(t_stack *s, t_stack *real);

/* simu_utils.c */

t_stack	ft_init_simu(t_stack *s);
int		ft_cpt_rr(t_count *tcr, int i);

/* decision_utils.c */

void	ft_r_decision(t_stack *s, t_count *c_r);
void	ft_rr_decision(t_stack *s, t_count *c_rr);
void	ft_rarrb_decision(t_stack *s, t_count *c_rarrb);
void	ft_rrarb_decision(t_stack *s, t_count *c_rrarb);

/* decision.c */

void	ft_decision(t_stack *s);

#endif
