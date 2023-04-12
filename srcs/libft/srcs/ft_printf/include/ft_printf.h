/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:46:18 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/11 09:42:17 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../../libft.h"

/* ft_bin_comp2.c */

char	*ft_itoa_base_comp2(long long nbr, const char *base,
			const char *base_hex);

/* ft_bin_to_hex.c */

char	*ft_bin_to_hex(char *s, const char *base_hex);

/* ft_convert_base.c */

char	*ft_itoa_base(long long nbr, const char *base, int len_base);
void	ft_print(char *str, int *cpt);
void	ft_convert_base(long long nbr, const char*base_from,
			const char *base_to, int *cpt);
void	ft_print_mem(void *p, const char *base_to, int *cpt);

/* ft_printf_utils.c */

void	ft_verif(va_list arg, const char c, int *cpt);

/* ft_printf.c */

int		ft_printf(const char *str, ...);

/* ft_putnbr_base.c */

void	ft_putnbr_base(int nbr, const char *base, int *cpt);

/* ft_putnbr_ui.c */

void	ft_putnbr_ui(unsigned int nb, int fd, int *cpt);

/* put_fd_printf.c */

void	ft_putnbr_printf_fd(int n, int fd, int *cpt);
void	ft_putstr_printf_fd(char *s, int fd, int *cpt);
void	ft_putchar_printf_fd(char c, int fd, int *cpt);

#endif