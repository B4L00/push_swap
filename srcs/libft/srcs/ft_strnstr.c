/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:43:09 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/08 13:43:11 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *) big);
	if (len == 0)
		return (0);
	while (big[i + j] && i + j < len)
	{
		if (big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *) big + i);
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (0);
}

/*
#include <stdio.h>

int main()
{
	printf("ft_strnstr : %s\n", ft_strnstr(((void*)0), "fake", 2));
	return 0;
}
*/