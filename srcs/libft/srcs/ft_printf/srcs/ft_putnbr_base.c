/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:30:31 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/11 09:23:48 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strlen_base(const char *base)
{
	int	cpt;
	int	cpt2;

	cpt = 0;
	while (base[cpt] != '\0')
	{
		cpt2 = cpt;
		while (base[cpt2] != '\0')
		{
			if (base[cpt2] == '+' || base[cpt2] == '-')
				return (0);
			if (cpt2 != cpt && base[cpt] == base[cpt2])
				return (0);
			cpt2++;
		}
		cpt++;
	}
	return (cpt);
}

void	ft_putnbr(long long nbr, const char *base, int len_base, int *cpt)
{
	if (nbr >= len_base)
	{
		ft_putnbr(nbr / len_base, base, len_base, cpt);
		nbr = nbr % len_base;
		write(1, base + nbr, 1);
		*cpt += 1;
	}
	else
	{
		nbr = nbr % len_base;
		write(1, base + nbr, 1);
		*cpt += 1;
	}
}

void	ft_putnbr_base(int nbr, const char *base, int *cpt)
{
	int				len_base;
	long long		n;

	n = nbr;
	len_base = ft_strlen_base(base);
	if (len_base < 2)
		return ;
	else if (n < 0)
	{
		write(1, "-", 1);
		*cpt += 1;
		ft_putnbr(-n, base, len_base, cpt);
	}
	else
	{
		ft_putnbr(n, base, len_base, cpt);
	}
}
