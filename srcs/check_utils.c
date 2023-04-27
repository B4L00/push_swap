/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:38:18 by larmenou          #+#    #+#             */
/*   Updated: 2023/04/27 13:40:00 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_utils(char *s, char **argv, int i)
{
	if (argv[i][0] == '+')
	{
		if (ft_strncmp(s, argv[i] +1, ft_strlen(argv[i])))
		{
			free(s);
			return (0);
		}
	}
	else if (ft_strncmp(s, argv[i], ft_strlen(argv[i])))
	{
		free(s);
		return (0);
	}
	return (1);
}
