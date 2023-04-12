/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:42:24 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/11 09:18:15 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_itoa_base(long long nbr, const char*base, int len_base)
{
	char	*dest;
	int		i;

	i = 64;
	dest = malloc(sizeof(char) * 65);
	if (dest == NULL)
		return (NULL);
	dest[i--] = 0;
	while (nbr / len_base >= 1 && i >= 0)
	{
		dest[i] = base[nbr % len_base];
		nbr = nbr / len_base;
		i--;
	}
	dest[i--] = base[nbr % len_base];
	while (i >= 0)
		dest[i--] = '0';
	return (dest);
}

void	ft_print(char *str, int *cpt)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (str[i] == '0' && i < len - 1)
		i++;
	write(1, str + i, len - i);
	*cpt += (len - i);
	free(str);
	return ;
}

void	ft_convert_base(long long nbr, const char *base_from,
						const char *base_to, int *cpt)
{
	const int	len_base_from = ft_strlen(base_from);
	const int	len_base_to = ft_strlen(base_to);
	char		*dest;

	if (len_base_from < 2 || len_base_to < 2)
		return ;
	if (nbr >= 0)
		dest = ft_itoa_base(nbr, base_to, len_base_to);
	else
		dest = ft_itoa_base_comp2(nbr, "01", base_to);
	if (!dest)
		return ;
	ft_print(dest, cpt);
	return ;
}

int	ft_verif_mem(unsigned long p, long long val, int *cpt)
{
	if (p == ULONG_MAX)
	{
		ft_putstr_printf_fd("0xffffffffffffffff", 1, cpt);
		return (1);
	}
	if (val == 0)
	{
		ft_putstr_printf_fd("(nil)", 1, cpt);
		return (1);
	}
	if (val == LONG_MIN)
	{
		ft_putstr_printf_fd("0x8000000000000000", 1, cpt);
		return (1);
	}
	return (0);
}

void	ft_print_mem(void *p, const char *base_to, int *cpt)
{
	long long	val;
	const int	len_base_to = ft_strlen(base_to);
	char		*dest;

	val = (long long)p;
	if (ft_verif_mem((unsigned long)p, val, cpt))
		return ;
	dest = ft_itoa_base(val, base_to, len_base_to);
	if (!dest)
		return ;
	ft_putstr_printf_fd("0x", 1, cpt);
	ft_print(dest, cpt);
	return ;
}
