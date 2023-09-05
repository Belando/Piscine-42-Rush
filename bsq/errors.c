/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:19:48 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/25 11:19:52 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushbsq.h"
#include <unistd.h>

int	print_error(int nb)
{
	if (nb == 1)
		write (2, "Error\n", 7);
	else if (nb == 2)
		write (2, "map error\n", 11);
	else if (nb == 3)
		write (2, "Memory allocation error\n", 25);
	else if (nb == 4)
		write (2, "Error opening file\n", 20);
	return (nb);
}
