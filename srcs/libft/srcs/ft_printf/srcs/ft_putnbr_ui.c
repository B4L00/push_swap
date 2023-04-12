/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:57:13 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/11 09:16:29 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_ui(unsigned int nb, int fd, int *cpt)
{
	if (nb > 9)
	{
		ft_putnbr_ui(nb / 10, fd, cpt);
		ft_putchar_printf_fd(nb % 10 + 48, fd, cpt);
	}
	else
		ft_putchar_printf_fd(nb % 10 + 48, fd, cpt);
}
