/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fd_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:11:36 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/11 09:33:41 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putchar_printf_fd(char c, int fd, int *cpt)
{
	write(fd, &c, 1);
	*cpt += 1;
}

void	ft_putstr_printf_fd(char *s, int fd, int *cpt)
{
	int	len;

	len = ft_strlen(s);
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		*cpt += 6;
		return ;
	}
	write(fd, s, len);
	*cpt += len;
}

void	ft_putnbr_printf_fd(int n, int fd, int *cpt)
{
	if (n == -2147483648)
	{
		ft_putstr_printf_fd("-2147483648", fd, cpt);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_printf_fd('-', fd, cpt);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_printf_fd(n / 10, fd, cpt);
		ft_putchar_printf_fd(n % 10 + 48, fd, cpt);
	}
	else
		ft_putchar_printf_fd(n % 10 + 48, fd, cpt);
}
