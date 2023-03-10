/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:53:58 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/07 14:54:00 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (!dest || !src || !n)
		return (dest);
	d = dest;
	s = src;
	i = 0;
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	//char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	//char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	//char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	printf("ft_memmove : %s\n", ft_memmove(s, s+2, 2));
	printf("%d\n", memcmp(s, sResult, 7));
	//printf("%p\n", &s);

	return 0;
}
*/