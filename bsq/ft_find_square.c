/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:16:32 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/26 14:16:45 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "rushbsq.h"

int	ft_find_square(char **map, int x, int y)
{
	t_find	f;

	f.rows = ft_read_map_data(map);
	f.t = 0;
	f.fail = 0;
	while ((x + f.t <= f.rows) && (y + f.t <= f.cols) && !f.fail)
	{
		f.i = 0;
		while ((f.i <= f.t) && !f.fail)
		{
			if (map[x + f.i][y + f.t] != f.empty)
				f.fail = 1;
			f.i++;
		}
		f.i = 0;
		while ((f.i <= f.t) && !f.fail)
		{
			if (map[x + f.t][y + f.i] != f.empty)
				f.fail = 1;
			f.i++;
		}
		if (!f.fail)
			f.t++;
	}
	return (f.t);
}
