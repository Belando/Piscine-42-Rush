/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:16:58 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/26 14:17:02 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rushbsq.h"

void	ft_print_result(char **map)
{
	t_find	f;

	f.i = ft_strlen(map[0]);
	f.j = 1;
	f.rows = 0;
	while (f.i - 3 > 0)
	{
		f.rows = (f.rows) + (f.j * (map[0][f.i - 4] - '0'));
		f.j *= 10;
		f.i--;
	}
	f.cols = ft_strlen(map[1]);
	f.i = 1;
	while (f.i < f.rows)
	{
		f.j = 0;
		while (f.j < f.cols)
		{
			write (1, &map[f.i][f.j], 1);
			f.j++;
		}
		f.i++;
		write (1, "\n", 1);
	}
}
