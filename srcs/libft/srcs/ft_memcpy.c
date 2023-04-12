/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:38:03 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/07 14:38:13 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (dest == 0 && src == 0)
		return (NULL);
	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char dest[100];
	memset(dest, 'A', 100);
	ft_memcpy(dest, "coucou", 0);
	printf("%s\n", dest);
	char src[] = {0, 0};
	ft_memcpy(dest, src, 2);
	printf("%s\n", dest);
	int i = 0;
	while (i < 100 && dest[i] == 0)
		i++;
	printf("%d  %c\n", i, dest[i]);
	//printf("memcpy : %p\n", memcpy(((void*)0), ((void*)0), 3));
	//printf("ft_memcpy : %p\n", ft_memcpy(((void*)0), ((void*)0), 3));
	return 0;
}
*/