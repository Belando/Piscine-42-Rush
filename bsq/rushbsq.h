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

typedef struct s_find
{
	int		i;
	int		t;
	int		rows;
	int		cols;
	int		fail;
	int		d;
	char	full;
	char	obstacle;
	int		fd;
	char	buffer[2048];
	char	**matrix;
	int		row;
	int		col;
	long	total_bytes;
	long	bytes_read;
	int		e;
	char	empty;
	int		count;
	char	**map_content;
	int		j;
	int		size;
	int		x;
	int		y;
	char	size_buffer[20];
	int		totalbytes;
	int		p;
	int		fre;
}	t_find;

int		print_error(int nb);
char	**read_map(char *filename, int *rows, int *columns);
void	free_map(char **matrix, int rows);
int		ft_strlen(char *str);
int		ft_str_is_printable(char *str);
int		ft_validate_map(char **map);
int		ft_find_square(char **map, int x, int y);
void	ft_fill(char **map_content, int x, int y, int size);
void	ft_print_result(char **map_content);
int		count_lines(char **map);
int		is_valid_char(char c);
int		is_valid_char_in_line(char c, char obstaculo, char vacio);
int		ft_read_map_data(char **map);
#endif