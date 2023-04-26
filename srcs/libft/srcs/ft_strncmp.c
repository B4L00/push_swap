/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:01:51 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/26 16:33:54 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!*s1 || !*s2)
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
	char *s1 = "23";
	char *s2 = "00023";
	printf("ft_strncmp : %d\n", (ft_strncmp(s1, s2, 5)));
	printf("strncmp : %d\n", (strncmp(s1, s2, 5)));
	return (0);
}
 */