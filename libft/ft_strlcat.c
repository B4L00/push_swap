/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:23:54 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/08 15:23:55 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendst;

	if (!dst && !size)
		return (ft_strlen(src));
	i = ft_strlen((const char *)dst);
	lendst = i;
	j = 0;
	if (i >= size)
		return (size + ft_strlen(src));
	while (src[j] && i < size - 1)
	{
			dst[i] = src[j];
			i++;
			j++;
	}
	dst[i] = src[ft_strlen(src)];
	return (lendst + ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int main()
{
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 
	strlen("there is no stars in the sky");

	printf("strlcat : %ld\n", strlcat(buff1, str, max));
	printf("strlcat : %s\n", buff1);
	printf("ft_strlcat : %ld\n", ft_strlcat(buff2, str, max));
	printf("ft_strlcat : %s\n", buff2);
	printf("max = %ld\n", max);
	printf("len : %d\n", ft_strlen(str));

	return 0;
}*/
