/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:30:02 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/26 13:35:14 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushbsq.h"

void	get_map_info(char **map, int *rows, int *cols, char *full, char *obstacle, char *empty)
{
	int	i;
	int	d;

	*full = map[0][i - 1];
	*obstacle = map[0][i - 2];
	*empty = map[0][i - 3];
	*cols = ft_strlen(map[1]);
	*rows = 0;
	d = 1;
	i = ft_strlen(map[0]);
	while (i - 3 > 0)
	{
		*rows = (*rows) + (d * (map[0][i - 4] - '0'));
		d *= 10;
		i--;
	}
}

int	check_square(char **map, int x, int y, int t, char empty)
{
	int	i;

	i = 0;
	while (i <= t)
	{
		if (map[x + i][y + t] != empty || map[x + t][y + i] != empty)
			return (0);
	}
	i++;
	return (1);
}

int	ft_find_square(char **map, int x, int y)
{
	int		rows;
	int		cols;
	int		t;
	char	full;
	char	obstacle;
	char	empty;

	get_map_info(map, &rows, &cols, &full, &obstacle, &empty);
	t = 0;
	while ((x + t <= rows) && (y + t <= cols))
	{
		if (!check_square(map, x, y, t, empty))
			break ;
		t++;
	}
	return (t);
}
