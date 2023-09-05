/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:25:14 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/26 14:25:18 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushbsq.h"

void	ft_fill(char **map, int x, int y, int size)
{
	int		i;
	int		j;
	char	full;

	i = ft_strlen(map[0]);
	full = map[0][i - 1];
	i = x;
	while (i < x + size)
	{
		j = y;
		while (j < y + size)
		{
			map[i][j] = full;
			j++;
		}
		i++;
	}
}
