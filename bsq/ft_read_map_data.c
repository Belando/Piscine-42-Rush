/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodri2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:31:54 by jarodri2          #+#    #+#             */
/*   Updated: 2023/07/26 17:31:58 by jarodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "rushbsq.h"

int	ft_read_map_data(char **map)
{
	t_find	f;

	f.i = ft_strlen(map[0]);
	f.obstacle = map[0][f.i - 2];
	f.empty = map[0][f.i - 3];
	f.full = map[0][f.i - 1];
	f.cols = ft_strlen(map[1]);
	f.rows = 0;
	f.d = 1;
	while (f.i - 3 > 0)
	{
		if (!((map[0][f.i - 4]) >= '0' && map[0][f.i - 4] <= '9'))
		{
			print_error(2);
		}
		f.rows = (f.rows) + (f.d * (map[0][f.i - 4] - '0'));
		f.d *= 10;
		f.i--;
	}
	return (f.rows);
}
