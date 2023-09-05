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
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**read_map(char *filename, int *rows, int *columns)
{
	int		fd;
	char	buffer[2048];
	char	**matrix;
	int		row;
	int		col;
	int		i;
	ssize_t	total_bytes;
	ssize_t	bytes_read;

	total_bytes = 0;
	row = 0;
	col = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error(4);
	matrix = (char **)malloc(2048 * sizeof(char));
	if (matrix == NULL)
	{
		close(fd);
		print_error(3);
	}
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
			{
				matrix[row][col] = '\0';
				row ++;
				col = 0;
			}
			else
			{
				if (matrix[row] == NULL)
				{
					matrix[row] = (char *)malloc(2048 * sizeof(char));
					if (matrix[row] == NULL)
					{
						close(fd);
						free_map (matrix, row);
						print_error(3);
					}
				}
				matrix[row][col] = buffer[i];
				col++;
			}
			i++;
		}
	}
	if (col > 0)
		matrix[row][col] = '\0';
	*rows = row +1;
	*columns = col;
	close(fd);
	return (matrix);
}
