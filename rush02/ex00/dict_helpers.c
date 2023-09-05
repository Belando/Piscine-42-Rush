/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 08:43:28 by jorgmar2          #+#    #+#             */
/*   Updated: 2023/07/23 16:23:54 by mhinarej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

long	ft_atoi(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (is_digit(str[i]))
	{
		result = result + (str[i] - '0');
		if (is_digit(str[i + 1]))
			result = result * 10;
		i++;
	}
	return (result);
}

long int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len ++;
		n = n / 10;
	}
	return (len);
}

char	*make_array(char *x, unsigned int number, long int len)
{
	while (number > 0)
	{
		x[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char			*x;
	long int		len;
	unsigned int	number;
	int				sign;

	sign = 1;
	len = ft_int_len(n);
	x = (char *)malloc(sizeof(char) * (len + 1));
	x[len--] = '\0';
	if (n == 0)
		x[0] = '0';
	if (n < 0)
		return (NULL);
	else
		number = n;
	x = make_array(x, number, len);
	return (x);
}
