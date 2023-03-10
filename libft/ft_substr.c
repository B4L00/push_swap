/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:50:15 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/08 16:50:16 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (start >= (unsigned int)ft_strlen(s))
	{
		dest = ft_calloc(1, sizeof(char));
		if (!dest)
			return (NULL);
		return (dest);
	}
	if ((unsigned int)ft_strlen(s) - start < len)
		dest = malloc(sizeof(char) * ((unsigned int)ft_strlen(s) - start + 1));
	if ((unsigned int)ft_strlen(s) - start >= len)
		dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (i < len && s[start])
	{
		dest[i++] = s[start++];
	}
	dest[i] = 0;
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *s = ft_substr("tripouille", 100, 1);

	printf("substr : %s\n", s);
	//printf("%d\n", ft_strlen(dest));
	printf("%d\n", strcmp(s, ""));
	free(s);
	return 0;
}
*/