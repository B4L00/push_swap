/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:36 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/08 13:21:38 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c_s1;
	const unsigned char	*c_s2;

	c_s1 = s1;
	c_s2 = s2;
	if (n == 0)
		return (0);
	while (*c_s1 == *c_s2 && n > 0)
	{
		n--;
		if (!n)
			return (*c_s1 - *c_s2);
		c_s1++;
		c_s2++;
	}
	return (*c_s1 - *c_s2);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("ft_memcmp : %d\n", ft_memcmp("NULL", "\0", 6));
	printf("memcmp : %d\n", memcmp("NULL", "\0", 6));
	return (0);
}
*/