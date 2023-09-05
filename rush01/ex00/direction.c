/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:58:29 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/17 10:40:06 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 4

//Conexión con otras funciones
int	compare(int grid[SIZE][SIZE], int row, char *arg);

//Añade las 4 vistas superiores a la string compare de iz a der
void	up(int grid[SIZE][SIZE], char *compare, int *count)
{
	int	i;
	int	j;
	int	result;
	int	h;

	j = 0;
	while (j < SIZE)
	{
		result = 1;
		i = 0;
		h = grid[i][j];
		while (++i < SIZE)
		{
			if (h < grid [i][j])
			{
				result++;
				h = grid[i][j];
			}
		}
		compare[*count] = result + '0';
		compare[*count + 1] = ' ';
		j++;
		*count = *count + 2;
	}
}

//Añade las 4 vistas inferiores de iz a der
void	down(int grid[SIZE][SIZE], char *compare, int *count)
{
	int	i;
	int	j;
	int	result;
	int	h;

	j = 0;
	while (j < SIZE)
	{
		result = 1;
		i = SIZE - 1;
		h = grid[i][j];
		while (--i >= 0)
		{
			if (h < grid [i][j])
			{
				result++;
				h = grid[i][j];
			}
		}
		compare[*count] = result + '0';
		compare[*count + 1] = ' ';
		j++;
		*count = *count + 2;
	}
}

//Añade las 4 vistas izquierdas de arriba a abajo
void	left(int grid[SIZE][SIZE], char *compare, int *count)
{
	int	i;
	int	j;
	int	result;
	int	h;

	i = 0;
	while (i < SIZE)
	{
		result = 1;
		j = 0;
		h = grid[i][j];
		while (++j < SIZE)
		{
			if (h < grid [i][j])
			{
				result++;
				h = grid[i][j];
			}
		}
		compare[*count] = result + '0';
		compare[*count + 1] = ' ';
		i++;
		*count = *count + 2;
	}
}

//Añade las 4 vistas derechas de arriba a abajo
void	right(int grid[SIZE][SIZE], char *compare, int *count)
{
	int	i;
	int	j;
	int	result;
	int	h;

	i = 0;
	while (i < SIZE)
	{
		result = 1;
		j = SIZE - 1;
		h = grid[i][j];
		while (--j >= 0)
		{
			if (h < grid [i][j])
			{
				result++;
				h = grid[i][j];
			}
		}
		compare[*count] = result + '0';
		compare[*count + 1] = ' ';
		i++;
		*count = *count + 2;
	}
}
