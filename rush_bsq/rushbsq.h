/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushbsq.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelando <fbelando@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:00:36 by fbelando          #+#    #+#             */
/*   Updated: 2023/07/25 11:00:39 by fbelando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSHBSQ_H
# define RUSHBSQ_H

int		print_error(int nb);
char	**read_map(char *filename, int *rows, int *columns);
void	free_map(char **matrix, int rows);
int		ft_strlen(char *str);
int		ft_str_is_printable(char *str);
int		ft_validate_map(char **map);
int		ft_find_square(char **map, int x, int y);
int		count_lines(char **map);
int		validate_header(char *header, char *full, char *obstacle, char *empty, int *lineas);
int		validate_line(char *line, int columnas, char obstaculo, char vacio);
int		is_valid_char(char c);
int		is_valid_char_in_line(char c, char obstaculo, char vacio);

#endif