/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:13:11 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/07 15:13:13 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (c > 256)
		c %= 256;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("ft_strrchr : %s\n", ft_strrchr("Bonjour", '\0'));
	printf("strrchr : %s\n", strrchr("Bonjour", '\0'));
	return (0);
}
*/