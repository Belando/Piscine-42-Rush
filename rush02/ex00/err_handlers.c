/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:27:32 by jorgmar2          #+#    #+#             */
/*   Updated: 2023/07/23 16:26:21 by mhinarej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>
#include <stdio.h>

void	print_error(int nb)
{
	if (nb == 1)
		write (1, "Error", 5);
	else if (nb == 2)
		write (1, "Dict Error", 10);
	else
		write (1, "Unknown Error", 13);
}

//	1 - Error  ||  0 - Okay
int	parse_number(char *number, int len)
{
	int	i;

	i = 0;
	if (!(number))
		return (1);
	while (i < len)
	{
		if (number[i] < '0' || number[i] > '9')
			return (1);
		i ++;
	}
	return (0);
}

// return 1 means error
// return another number means okay
int	parse_input(int argc, char *argv[])
{
	char	*number;
	int		error;
	int		arg_len;

	if (argc == 2)
		number = argv[1];
	if (argc == 3)
		number = argv[2];
	if (argc < 2 || argc > 3)
		return (1);
	else
	{
		arg_len = ft_len(number);
		error = parse_number(number, arg_len);
		return (error);
	}
}
