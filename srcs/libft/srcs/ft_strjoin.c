/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:05:25 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/08 17:05:26 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dest;
	int			i;
	int			j;
	const int	len1 = ft_strlen(s1);
	const int	len2 = ft_strlen(s2);

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dest)
		return (0);
	while (i < len1 + len2)
	{
		if (i < len1)
			dest[i] = s1[i];
		else
		{
			dest[i] = s2[j];
			j++;
		}
		i++;
	}
	dest[i] = 0;
	return (dest);
}
