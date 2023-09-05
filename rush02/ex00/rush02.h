/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgmar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:28:40 by jorgmar2          #+#    #+#             */
/*   Updated: 2023/07/22 11:48:55 by mhinarej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

int		parse_input(int argc, char *argv[]);
void	print_error(int nb);
void	ft_putstr(char *str);
int		ft_len(char *str);
int		dict(char *filename, int search);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strcpy(char *dest, char *src);
int		is_digit(char c);
long	ft_atoi(char *str);
char	*ft_itoa(int n);
int		ft_strposition(char *str, char *tofind);
void	print_billion(unsigned int num, char *dict);
void	print_million(int num, char *dict);
void	print_thousand(int num, char *dict);
void	print_hundred(int num, char *dict);
void	print_tens(int num, char *dict);
int		breakdown_number(long num, char *dict);
char	*get_dict_value(int key, char *dict);
char	*read_dictionary(char *filename);
#endif
