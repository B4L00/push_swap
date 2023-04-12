/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:22:21 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/11 09:33:10 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	int			cpt;
	va_list		arg;

	va_start(arg, str);
	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_verif(arg, str[i], &cpt);
		}
		else
			ft_putchar_printf_fd(str[i], 1, &cpt);
		i++;
	}
	va_end(arg);
	return (cpt);
}
