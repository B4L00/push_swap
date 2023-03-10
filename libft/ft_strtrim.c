/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:20:03 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/09 13:20:05 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_start(char *s1, char *set)
{
	int	j;
	int	i;
	int	isnset;

	i = 0;
	isnset = 0;
	while (s1[i] && !isnset)
	{
		j = 0;
		while (set[j] && !isnset)
		{
			if (set[j] != s1[i] && j == ft_strlen(set) - 1)
			{
				isnset = 1;
				return (i);
			}
			else if (set[j] == s1[i])
				break ;
			j++;
		}
		i++;
	}
	return (i);
}

static int	ft_find_end(char *s1, char *set)
{
	int	j;
	int	i;
	int	isnset;

	i = ft_strlen(s1) - 1;
	isnset = 0;
	while (s1[i] && !isnset)
	{
		j = 0;
		while (set[j] && !isnset)
		{
			if (set[j] != s1[i] && j == ft_strlen(set) - 1)
			{
				isnset = 1;
				return (i);
			}
			else if (set[j] == s1[i])
				break ;
			j++;
		}
		i--;
	}
	return (i);
}

static char	*ft_fill_dest(char *s1, char *dest, unsigned int start,
unsigned int end)
{
	int	k;

	k = 0;
	while (start <= end)
	{
		dest[k] = s1[start];
		k++;
		start++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		start;
	int		end;

	if (!*set || !*s1)
	{
		dest = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
		if (!dest)
			return (NULL);
		return (ft_fill_dest((char *)s1, dest, 0, ft_strlen((char *)s1)));
	}
	start = ft_find_start((char *)s1, (char *)set);
	end = ft_find_end((char *)s1, (char *)set);
	if (start == ft_strlen(s1) && end == -1)
	{
		dest = ft_calloc(1, sizeof(char));
		if (!dest)
			return (NULL);
		return (dest);
	}
	dest = malloc(sizeof(char) * (end - start + 2));
	if (!dest)
		return (NULL);
	dest[end - start + 1] = 0;
	return (ft_fill_dest((char *)s1, dest, start, end));
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *s = ft_strtrim("123", "");
	printf("ft_strtrim : %s\n", s);
	printf("strcmp : %d\n", strcmp(s, ""));
	free(s);
	return (0);
}
*/