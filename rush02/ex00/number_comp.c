/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:20:00 by jorgmar2          #+#    #+#             */
/*   Updated: 2023/07/23 16:37:47 by mhinarej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>

void	print_billion(unsigned int num, char *dict)
{	
	breakdown_number(num / 1000000000, dict);
	ft_putstr(get_dict_value(1000000000, dict));
	breakdown_number(num % 1000000000, dict);
}

void	print_million(int num, char *dict)
{
	breakdown_number(num / 1000000, dict);
	ft_putstr(get_dict_value(1000000, dict));
	breakdown_number(num % 1000000, dict);
}

void	print_thousand(int num, char *dict)
{
	breakdown_number(num / 1000, dict);
	ft_putstr(get_dict_value(1000, dict));
	breakdown_number(num % 1000, dict);
}

void	print_hundred(int num, char *dict)
{
	breakdown_number(num / 100, dict);
	ft_putstr(get_dict_value(100, dict));
	breakdown_number(num % 100, dict);
}

void	print_tens(int num, char *dict)
{
	ft_putstr(get_dict_value((num / 10) * 10, dict));
	breakdown_number(num % 10, dict);
}
