/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:08:57 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/25 11:09:03 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rushbsq.h"

void	free_map(char **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		i++;
	}
	free(matrix);
}

char	**read_map(char *filename, int *rows, int *columns)
{
	t_find	f;

	f.total_bytes = 0;
	f.row = 0;
	f.col = 0;
	f.i = 0;
	f.fd = open(filename, O_RDONLY);
	if (f.fd == -1)
		print_error(4);
	f.matrix = (char **)malloc(4096 * sizeof(char *));
	if (f.matrix == NULL)
	{
		close(f.fd);
		print_error(3);
	}
	f.bytes_read = read(f.fd, f.buffer, sizeof(f.buffer));
	while (f.bytes_read > 0)
	{
		while (f.i < f.bytes_read)
		{
			if (f.buffer[f.i] == '\n')
			{
				f.matrix[f.row][f.col] = '\0';
				f.row ++;
				f.col = 0;
			}
			else
			{
				if (f.matrix[f.row] == '\0')
				{
					f.matrix[f.row] = (char *)malloc(4096 * sizeof(char));
					if (f.matrix[f.row] == '\0')
					{
						close(f.fd);
						print_error(3);
						free_map (f.matrix, f.row);
					}
				}
				f.matrix[f.row][f.col] = f.buffer[f.i];
				f.col++;
			}
			f.i++;
		}
		f.bytes_read = read(f.fd, f.buffer, sizeof(f.buffer));
	}
	*rows = f.row + 1;
	*columns = f.col;
	close(f.fd);
	return (f.matrix);
}
