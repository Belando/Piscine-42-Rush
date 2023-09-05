/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:24:57 by jorgmar2          #+#    #+#             */
/*   Updated: 2023/07/22 00:25:04 by jorgmar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "unistd.h"

int	main(int argc, char *argv[])
{
	char	dictionary[1024];
	long	number;

	if (parse_input(argc, argv) == 1)
		print_error(1);
	else
	{
		if (argc == 2)
		{
			number = ft_atoi(argv[1]);
			ft_strcpy(dictionary, read_dictionary("numbers.dict"));
		}
		if (argc == 3)
		{
			if (read_dictionary(argv[1]) == 0)
				return (1);
			ft_strcpy(dictionary, read_dictionary(argv[1]));
			number = ft_atoi(argv[2]);
		}
		breakdown_number(number, dictionary);
	}
	write(1, "\n", 1);
	return (0);
}
