/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:05:19 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/23 12:35:17 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	alloc = malloc(size * nmemb);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, nmemb * size);
	return (alloc);
}

/*#include <stdio.h>

int main()
{
	int i = 5;
	char *dest = ft_calloc(536870912, 4);
	char *dest2 = calloc(536870912, 4);
	while (i > 0)
	{
		printf("ft_calloc : %c\n", *dest);
		dest++;
		i--;
	}
	i = 5;
	printf("\n\n");
	while (i > 0)
	{
		printf("calloc : %c\n", *dest2);
		dest2++;
		i--;
	}
	
	return (0);
}

int	main(void)
{
	char	*s;

	s = ft_calloc(SIZE_MAX, SIZE_MAX);
	if (s)
		printf("yay\n");
	else
		printf("ohh\n");
	return (0);
}*/
