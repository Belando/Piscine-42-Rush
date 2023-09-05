/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:03:57 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/16 18:04:18 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//Ejercicio de clase que compara cadenas de char, si son válidas return (0)
int	ft_strcmp(char *s1, char *s2)
{
	int	difference;

	difference = 0;
	while (s1[difference] == s2[difference] && s1[difference] != '\0')
		difference++;
	return (s1[difference] - s2[difference]);
}
