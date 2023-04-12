/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:07:48 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/07 15:07:49 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c > 256)
		c %= 256;
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("ft_strchr : %s\n", ft_strchr("bonjour", '\0'));
	printf("strchr : %s\n", strchr("bonjour", '\0'));
	return (0);
}
*/