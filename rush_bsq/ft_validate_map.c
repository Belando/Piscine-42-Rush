/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarodri2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:32:38 by jarodri2          #+#    #+#             */
/*   Updated: 2023/07/25 12:41:15 by jarodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "rushbsq.h"

int	validate_line(char *line, int columnas, char obstaculo, char vacio)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
		i++;
	if (i != columnas)
		return (0);
	while (j < columnas)
	{
		if (!is_valid_char_in_line(line[j], obstaculo, vacio))
			return (0);
		j++;
	}
	return (1);
}

int	validate_header(char *header, char *full, char *obstacle, char *empty, int *lineas)
{
	int	i;
	int	d;

	i = 0;
	d = 1;
	*lineas = 0;
	while (header[ft_strlen(header) - i - 4] >= '0' && header[ft_strlen(header) - i - 4] <= '9')
	{
		*lineas += (d * (header[ft_strlen(header) - i - 4] - '0'));
		d *= 10;
		i++;
	}
	*full = header[ft_strlen(header) - 1];
	*obstacle = header[ft_strlen(header) - 2];
	*empty = header[ft_strlen(header) - 3];
	if (!is_valid_char(*full) || !is_valid_char(*obstacle) || !is_valid_char(*empty))
	{
		write(2, "no printable\n", 13);
		return (0);
	}
	return (1);
}

int	ft_validate_map(char **map)
{
	int		rows;
	int		cols;
	char	full;
	char	obstacle;
	char	vacio;
	int		i;

	rows = 0;
	i = 0;
	if (!validate_header(map[0], &full, &obstacle, &vacio, &rows))
		return (0);
	if (count_lines(map) != rows)
		return (0);
	cols = ft_strlen(map[1]);
	while (i <= rows)
	{
		if (ft_strlen(map[i]) != cols)
			return (0);
		if (!validate_line(map[i], cols, obstacle, vacio))
			return (0);
		i++;
	}
	return (1);
}
