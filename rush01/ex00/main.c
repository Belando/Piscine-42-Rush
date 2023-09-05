/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:55:05 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/17 10:36:10 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 4

//Colocamos todas las funciones a las que llamamos desde main para poder
//coser los archivos al compilar
int	generate(int grid[SIZE][SIZE], int roww, int col, char *arg);

//Función main principal, comprueba si recibe 2 argumentos unicamente
//en caso de no encontrar el grid o mal imput, muestra Error
int	main(int argc, char **argv)
{
	int	grid[SIZE][SIZE];

	if (argc == 2)
	{
		if (generate(grid, 0, 0, argv[1]) == 0)
		{
			write (1, "Error\n", 6);
			return (0);
		}
	}
	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
}
