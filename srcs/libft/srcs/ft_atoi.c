/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:24:01 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/27 08:33:38 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	isneg;

	isneg = 0;
	result = 0;
	i = ft_whitespace((char *)nptr);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			isneg = 1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			result = result * 10 + (nptr[i++] - 48);
		else
			break ;
	}
	if (isneg)
		result = -result;
	return (result);
}

/* 
#include <stdio.h>

int main()
{
	printf("ft_atoi : %d\n", ft_atoi("-0006"));
	printf("atoi : %d\n", atoi("-0006"));
	return (0);
}
 */