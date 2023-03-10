/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:42:48 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/08 14:42:49 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main()
{
	char *str = "BBBB";
	char buff1[0xF00];
	char buff2[0xF00];

	memset(buff1, 'A', 20);
	memset(buff2, 'A', 20);
	ft_strlcpy(buff2, str, 0);
	strlcpy(buff1, str, 0);
	printf("strlcpy : %s\n", buff1);
	printf("ft_strlcpy : %s\n", buff2);

	return (0);
}
*/