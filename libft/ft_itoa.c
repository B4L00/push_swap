/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:24:30 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/11 09:24:32 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb(long nb)
{
	int	cpt;

	cpt = 0;
	if (nb <= 0)
	{
		cpt++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		cpt++;
	}
	return (cpt);
}

static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		cpt;
	char	*s;

	cpt = ft_nb(n);
	s = malloc(sizeof(char) * (cpt + 1));
	if (!s)
		return (0);
	s[cpt] = '\0';
	cpt--;
	if (n == 0)
		s[cpt] = '0';
	while (cpt >= 0 && n != 0)
	{
		if (cpt == 1 && n < 0)
			s[cpt - 1] = '-';
		s[cpt] = ft_abs(n) % 10 + 48;
		n /= 10;
		cpt--;
	}
	return (s);
}

/*
#include <stdio.h>
int main()
{
	char *s = ft_itoa(INT_MIN);
	printf("ft_itoa : %s\n", s);
	free(s);
	return 0;
}
*/