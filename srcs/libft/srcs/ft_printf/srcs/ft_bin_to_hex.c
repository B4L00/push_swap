/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:34:09 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/11 09:17:53 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_pow(int p)
{
	int	res;

	res = 1;
	if (p == 0)
		return (res);
	else
		return (2 * ft_pow(p - 1));
}

char	*ft_convert_hex(char *s, char *dest, const char *base_hex,
						const int len)
{
	int	res;
	int	pow;
	int	i;

	i = 0;
	pow = 3;
	res = 0;
	while (i < len)
	{
		if (s[i] == '1')
			res += ft_pow(pow);
		pow--;
		if (pow == -1)
		{
			pow = 3;
			dest[i / 4] = base_hex[res];
			res = 0;
		}
		i++;
	}
	dest[i / 4] = 0;
	free(s);
	return (dest);
}

char	*ft_bin_to_hex(char *s, const char *base_hex)
{
	char		*dest;
	const int	len = ft_strlen(s);

	dest = malloc(sizeof(char) * 9);
	if (!dest)
		return (NULL);
	return (ft_convert_hex(s, dest, base_hex, len));
}
