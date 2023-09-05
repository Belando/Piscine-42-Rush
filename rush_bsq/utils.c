/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:14:59 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/26 13:15:04 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushbsq.h"

int	ft_strlen(char *str)
{
	int	large;

	large = 0;
	while (*str != '\0')
	{
		large++;
		str++;
	}
	return (large);
}

int	ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 32 && *(str + i) <= 126)
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	count_lines(char **map)
{
	int	count;

	count = 0;
	while (map[count] != '\0')
		count++;
	return (count - 1);
}

int	is_valid_char(char c)
{
	return (c >= 32 && c <= 126);
}

int	is_valid_char_in_line(char c, char obstaculo, char vacio)
{
	return (c == obstaculo || c == vacio);
}
