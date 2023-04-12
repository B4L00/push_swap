/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_comp2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:53:38 by larmenou          #+#    #+#             */
/*   Updated: 2023/01/24 09:53:40 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

char	*ft_inverse(char *dest, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (dest[i] == '0')
			dest[i] = '1';
		else
			dest[i] = '0';
		i++;
	}
	return (dest);
}

char	*ft_add_one(char *dest, int len)
{
	int	ret;
	int	i;

	ret = 1;
	i = len - 1;
	while (i >= 0)
	{
		if (dest[i] == '0' && ret == 1)
		{
			dest[i] = '1';
			break ;
		}
		else if (dest[i] == '1' && ret == 1)
			dest[i] = '0';
		i--;
	}
	return (dest);
}

char	*ft_itoa_base_comp2(long long nbr, const char *base,
							const char *base_hex)
{
	char	*dest;
	int		len;

	nbr = -nbr;
	dest = ft_itoa_base(nbr, base, ft_strlen(base));
	if (!dest)
		return (NULL);
	len = ft_strlen(dest);
	ft_inverse(dest, len);
	ft_add_one(dest, len);
	return (ft_bin_to_hex(dest, base_hex));
}
