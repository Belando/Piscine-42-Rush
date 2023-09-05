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

int	main(void)
{
	char	*filename;
	char	**map_content;
	int		rows;
	int		columns;
	int		i;
	int		j;
	int		t;
	int		tamaño;
	int 	x;
	int		y;
	char	size_buffer[20];
	int		totalbytes;

	filename = "map.txt";
	rows = 0;
	columns = 0;
	map_content = read_map(filename, &rows, &columns);
	if (map_content != NULL)
	{
		totalbytes = rows * columns;
		i = 0;
		while (totalbytes > 0)
		{
			size_buffer[i] = '0' + (totalbytes % 10);
			totalbytes /= 10;
			i++;
		}
		size_buffer[i] = '\0';
		while (i > 0)
			i--;
		i = 0;
		while (i < rows)
		{
			j = 0;
			while (j < columns && map_content[i][j] != '\0')
				j++;
			i++;
		}
		printf ("valido=%d\n",ft_validate_map (map_content));
		i = 1;
		while (i < rows)
		{
			j = 0;
			while (j < columns)
			{
				t = ft_find_square(map_content,i,j);
				if (t > tamaño)
					{
						tamaño = t;
						x = i;
						y = j;
					}
				j++;
			}
			i++;
		}


		printf ("x=%d, y=%d ,tamaño=%d\n",x, y, tamaño);
		free_map(map_content, rows);
	}
	else
		print_error(4);
	return (0);
}
