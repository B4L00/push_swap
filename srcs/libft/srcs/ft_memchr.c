/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:41:48 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/08 09:41:50 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cpy;
	size_t			i;

	i = 0;
	cpy = (void *) s;
	if (c > 256)
		c %= 256;
	while (i < n)
	{
		if (*cpy == c)
			return (cpy);
		cpy++;
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *src = "Bonjour \0 a tous";
	int size = 10;
	//printf("%p\n", &src[8]);
	printf("ft_memchr : %p\n", ft_memchr(src, 'r' + 256, size));
	printf("memchr : %p\n", memchr(src, 'r' + 256, size));
	printf("memchr : %p\n", memchr(src, 'r', size));
	//printf("t = %c\nt + 1024 = %c\n", 't', 't' + 1024);
	//printf("t = %d\n t + 256 = %d\n", 't', ('t' + 1024) % 256);
	return (0);
}
*/