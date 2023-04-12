/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:01:51 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/08 09:01:53 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((!*s1 || !*s2) && n == 0)
		return (0);
	if (n == 0)
		return (0);
	while (*s1 == *s2 && n > 0)
	{
		n--;
		if (!n)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *s1 = "hHfluqVB";
	char *s2 = "GhCEt90oxFH";
	printf("ft_strncmp : %d\n", (ft_strncmp(s1, s2, 0)));
	printf("strncmp : %d\n", (strncmp(s1, s2, 0)));
	return (0);
}
*/