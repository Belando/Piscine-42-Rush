/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:27:28 by cmedeiro          #+#    #+#             */
/*   Updated: 2023/07/11 13:19:01 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y)
{
	int	c;
	int	f;

	f = 0;
	while (f < y)
	{
		c = 0;
		while (c < x)
		{
			if ((c == x - 1 && f == y - 1) || (c == 0 && f == y - 1))
				write(1, "A", 1);
			if ((f == 0 || f == y - 1) && c >= 1 && c <= x - 2)
				write(1, "B", 1);
			if ((c == 0 || c == x - 1) && f >= 1 && f <= y - 2)
				write(1, "D", 1);
			if ((c == 0 && f == 0) || (c == x - 1 && f == 0))
				write(1, "C", 1);
			if (f >= 1 && f <= y - 2 && c >= 1 && c <= x - 2)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		f++;
	}
}
