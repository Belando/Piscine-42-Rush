/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:26:15 by jorgmar2          #+#    #+#             */
/*   Updated: 2023/07/23 16:21:32 by mhinarej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rush02.h"

//read the dictionary and return it as a string
char	*read_dictionary(char *filename)
{
	int			fd;
	static char	buffer[1024];
	ssize_t		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(2);
		return (NULL);
	}
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
}

int	breakdown_number(long num, char *dict)
{
	if (num > 4294967295)
	{
		print_error(1);
		return (0);
	}	
	if (num >= 1000000000)
		print_billion(num, dict);
	else if (num >= 1000000)
		print_million(num, dict);
	else if (num >= 1000)
		print_thousand(num, dict);
	else if (num >= 100)
		print_hundred(num, dict);
	else if (num >= 20 && num <= 90)
		print_tens(num, dict);
	else if (num >= 10 && num <= 19)
		ft_putstr(get_dict_value(num, dict));
	else if (num >= 0 && num <= 9)
		ft_putstr(get_dict_value(num, dict));
	return (0);
}

// We start right from the last line break before we find it
char	*get_from_position(char *dict, int pos)
{
	int			i;
	int			j;
	static char	value[50];

	i = pos + 1;
	j = 0;
	while (dict[i] == ' ' && dict[i - 1] == ':')
		i++;
	while (dict[i] != '\n')
	{
		if (is_digit(dict[i]))
			i++;
		else if (dict[i] == ' ' && dict[i + 1] == ' ')
			i++;
		else if (dict[i] == ':')
			i++;
		else
		{
			value[j] = dict[i];
			i++;
			j++;
		}
	}
	value[j] = '\0';
	return (value);
}

// you pass it a key and a dictionary and it returns the value
char	*get_dict_value(int key, char *dict)
{
	char	*keystr;
	int		position;
	char	*value;

	keystr = ft_itoa(key);
	position = ft_strposition(dict, keystr);
	if (position == -1)
	{
		print_error(2);
		return (NULL);
	}
	else
		value = get_from_position(dict, position);
	return (value);
}
