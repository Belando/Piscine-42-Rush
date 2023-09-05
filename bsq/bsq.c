/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:10:36 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/25 12:10:49 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushbsq.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_find	f;

	if (argc > 1)
	{
		f.p = 1;
		while (f.p < argc)
		{
			f.rows = 0;
			f.cols = 0;
			f.map_content = read_map(argv[f.p], &f.rows, &f.cols);
			if (f.map_content != NULL)
			{
				if (!ft_validate_map(f.map_content))
					print_error(2);
				else
				{
					f.t = ft_find_square(f.map_content, 1, 0);
					if (f.t > f.size)
					{
						f.size = f.t;
						f.x = 1;
						f.y = 0;
					}
					if (f.size > 0)
					{
						ft_fill(f.map_content, f.x, f.y, f.size);
						ft_print_result(f.map_content);
					}
					free_map(f.map_content, f.rows);
				}
			}
			else
				print_error(4);
			f.p++;
			if (f.p < argc)
				write(1, "\n", 1);
		}
	}
	return (0);
}
