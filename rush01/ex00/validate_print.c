/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:36:21 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/17 10:25:47 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 4

static const int	g_e[SIZE] = {1, 2, 3, 4};

int		ft_strcmp(char *s1, char *s2);
void	down(int grid[SIZE][SIZE], char *compare, int *count);
void	up(int grid[SIZE][SIZE], char *compare, int *count);
void	left(int grid[SIZE][SIZE], char *compare, int *count);
void	right(int grid[SIZE][SIZE], char *compare, int *count);

//Llama a la funcion ft_strcmp y verifica si es el resultado pedido
//En caso de ser el resultado pedido, imprime el grid y acaba el programa
int	print(int grid[SIZE][SIZE], char *compare, char *arg)
{
	int		i;
	int		j;
	char	printer;

	if (ft_strcmp(arg, compare) == 0)
	{
		i = 0;
		while (i < SIZE)
		{
			j = 0;
			while (j < SIZE)
			{
				printer = grid [i][j] + '0';
				write (1, &printer, 1);
				if (j < (SIZE - 1))
					write (1, " ", 1);
				j++;
			}
			write (1, "\n", 1);
			i++;
		}
		return (1);
	}
	return (0);
}

//Llama a las funciones de las 4 vistas y escribe la string
//Despues llama a print y, si es igual que la pedida, imprime el grid.
int	compare(int grid[SIZE][SIZE], int row, char *arg)
{
	int		count;
	char	compare[100];

	count = 0;
	if (row == SIZE)
	{
		up(grid, compare, &count);
		down(grid, compare, &count);
		left(grid, compare, &count);
		right(grid, compare, &count);
		compare[count - 1] = '\0';
		if (print(grid, compare, arg) == 1)
			return (1);
	}
	return (0);
}

//Tras colocar el primer número válido en el grid
//Se mueve a la siguiente casilla
void	next(int *nextrow, int *nextcol, int *row, int *col)
{
	*nextrow = *row;
	*nextcol = *col + 1;
	if (*nextcol == SIZE)
	{
		*nextrow = *nextrow + 1;
		*nextcol = 0;
	}
}

//Comprueba si el número está repetido en fila o columna antes de colocarlo
int	validate(int grid[SIZE][SIZE], int row, int col, int value)
{
	int	k;

	k = 0;
	while (k < col)
	{
		if (grid[row][k] == value || grid[k][col] == value)
			return (0);
		k++;
	}
	return (1);
}

//Comienza a generar un grid válido, función que se llama a si misma 
//hasta encontrar todos los resultados (+570)
//Es la función principal que se comunica con el resto.
int	generate(int grid[SIZE][SIZE], int row, int col, char *arg)
{
	int	i;
	int	nextrow;
	int	nextcol;

	if (compare(grid, row, arg) == 1)
		return (1);
	i = -1;
	if (row == SIZE)
		return (0);
	while (++i < SIZE)
	{
		if (validate(grid, row, col, g_e[i]))
		{
			grid[row][col] = g_e[i];
			next(&nextrow, &nextcol, &row, &col);
			if (generate(grid, nextrow, nextcol, arg) == 1)
				return (1);
			grid[row][col] = 0;
		}
	}
	return (0);
}
