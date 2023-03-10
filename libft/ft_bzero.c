/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:31:28 by larmenou          #+#    #+#             */
/*   Updated: 2022/11/07 14:31:35 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*
#include <stdio.h>
#include <strings.h>
int main()
{
	char s[10];
	char r[10];
	ft_bzero(s, 10);
	bzero(r, 10);
	printf("%c\n", s[5]);
	printf("%c\n", r[5]);

	return 0;
}
*/