/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodri2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:32:38 by jarodri2          #+#    #+#             */
/*   Updated: 2023/07/25 12:41:15 by jarodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "rushbsq.h"

int	ft_validate_map(char **map)
{
	t_find	f;

	f.i = 0;
	f.rows = 0;
	f.count = 1;
	f.i = ft_strlen(map[0]);
	if (f.i < 4)
		print_error(2);
	f.e = f.i - 4;
	if (!(ft_str_is_printable(map[0])))
		return (0);
	f.rows = ft_read_map_data(map);
	f.obstacle = map[0][f.i - 2];
	f.empty = map[0][f.i - 3];
	while (map[f.count])
		f.count++;
	while (f.i - 3 > 0)
	{
		if (!((map[0][f.i - 4]) >= '0' && map[0][f.i - 4] <= '9'))
			return (0);
		f.i--;
	}
	if (f.rows != f.count -1)
		return (0);
	f.i = 1;
	f.cols = ft_strlen(map[1]);
	while (f.i <= f.rows)
	{
		f.e = 0;
		while (f.e < f.cols)
		{
			if (ft_strlen(map[f.i]) != f.cols)
				return (0);
			if (!((map[f.i][f.e] == f.obstacle)
				|| (map[f.i][f.e] == f.empty)))
				return (0);
			f.e++;
		}	
		f.i++;
	}
	return (1);
}
