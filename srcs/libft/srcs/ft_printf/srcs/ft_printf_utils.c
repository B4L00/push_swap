/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:33:15 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/11 09:21:50 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_uint(va_list arg, const char c, int *cpt)
{
	if (c == 'u')
		ft_putnbr_ui(va_arg(arg, unsigned int), 1, cpt);
	else if (c == 'x')
		ft_convert_base(va_arg(arg, unsigned int), "0123456789",
			"0123456789abcdef", cpt);
	else if (c == 'X')
		ft_convert_base(va_arg(arg, unsigned int), "0123456789",
			"0123456789ABCDEF", cpt);
	return ;
}

void	ft_int(va_list arg, const char c, int *cpt)
{
	if (c == 'c')
		ft_putchar_printf_fd(va_arg(arg, int), 1, cpt);
	else if (c == 'd')
		ft_putnbr_printf_fd(va_arg(arg, int), 1, cpt);
	else if (c == 'i')
		ft_putnbr_base(va_arg(arg, int), "0123456789", cpt);
}

void	ft_verif(va_list arg, const char c, int *cpt)
{
	if (c == 'c' || c == 'd' || c == 'i')
		ft_int(arg, c, cpt);
	else if (c == 's')
		ft_putstr_printf_fd(va_arg(arg, char *), 1, cpt);
	else if (c == 'p')
		ft_print_mem(va_arg(arg, void *), "0123456789abcdef", cpt);
	else if (c == 'u' || c == 'x' || c == 'X')
		ft_uint(arg, c, cpt);
	else if (c == '%')
		ft_putchar_printf_fd('%', 1, cpt);
	else
	{
		ft_putchar_printf_fd('%', 1, cpt);
		ft_putchar_printf_fd(c, 1, cpt);
	}
	return ;
}
