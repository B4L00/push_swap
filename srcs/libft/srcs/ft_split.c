/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 08:47:23 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/25 15:37:37 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cptword(char *s, char c)
{
	int	i;
	int	cpt;
	int	iscset;

	i = 0;
	cpt = 0;
	iscset = 1;
	while (s[i])
	{
		if (s[i] != c && iscset)
		{
			cpt++;
			iscset = 0;
		}
		else if (s[i] == c)
			iscset = 1;
		i++;
	}
	return (cpt);
}

static int	ft_cptletter(char *s, char c)
{
	int	cpt;

	cpt = 0;
	while (*s != c && *s)
	{
		cpt++;
		s++;
	}
	return (cpt);
}

static void	ft_fill(char *s, char **sentence, int cpt, int i)
{
	int	j;

	j = 0;
	while (j < cpt)
	{
		sentence[i][j] = s[j];
		j++;
	}
	sentence[i][j] = 0;
}

static char	**ft_free(char **sentence)
{
	int	i;

	i = 0;
	while (sentence[i])
	{
		free(sentence[i]);
		i++;
	}
	free(sentence);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**sentence;
	int		i;
	int		cpt;

	i = 0;
	sentence = malloc(sizeof(char *) * (ft_cptword((char *)s, c) + 1));
	if (!sentence)
		return (0);
	while (*s)
	{
		cpt = ft_cptletter((char *)s, c);
		if (cpt)
		{
			sentence[i] = malloc(sizeof(char) * (cpt + 1));
			if (!sentence[i])
				return (ft_free(sentence));
			ft_fill((char *)s, sentence, cpt, i);
			i++;
			s += cpt;
		}
		else
			s++;
	}
	sentence[i] = 0;
	return (sentence);
}
