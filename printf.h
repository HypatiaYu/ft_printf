/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:15:22 by hyu               #+#    #+#             */
/*   Updated: 2020/02/06 16:17:57 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft/libft.h"

typedef	struct		s_point
{
	int				parameter;
	int				flags;
	int				alignment;
	int				fill;
	//int				plus;
	int				width;
	int				string;
	int				base;
	int				prepend;
	int				prepend_number;
	int				int_char;
	int				other_type;
	int				precision;
	int				length;
	int				type;
	int				total_num;
}					t_point;

typedef	void print_function(t_point *storage, va_list valist);

typedef struct s_dispatch_table
{
	char	c;

	void		(*function)();
	/* data */
}				t_dispatch_table;

//typedef int		conversion_function(t_point *storage, va_list valist);

int     ft_printf(char *str, ...);
int     digits_base(int n, int base);
void    str_scan(const char *str, int *i, t_point *storage);
void	assign_tpoint(char *str, int *i, t_point *storage, va_list valist);
int     is_percentage(char c);
void	check_type(char *str, int *i, t_point *character);
void	check_flags(char *str, int *i, t_point *character, va_list valist);
void	check_width(char *str, int *i, t_point *character, va_list valist);
void     check_precisions(char *str, int *i, t_point *character, va_list valist);
void		check_length(char *str, int *i, t_point *character);
void		printf_integer_10(t_point *storage, va_list valist);
void		print_string(t_point *storage, va_list valist);
void	printf_character(t_point *storage, va_list valist);
void		print_string_int(t_point *storage, va_list valist);
void    default_settings(t_point *storage);
void    ft_putnbr_base(int num, int base);
void    ft_putnbr_BASE(int num, int base);
void	printf_INT_16(t_point *storage, va_list valist);
void	printf_integer_16(t_point *storage, va_list valist);
void	printf_integer_10(t_point *storage, va_list valist);
void	printf_integer_8(t_point *storage, va_list valist);
void	print_byte_hex(int	i);
void    storage_fill(t_point *storage);
void    print_prepend(t_point *storage);
void	storage_fill_int(t_point *storage, int base, int i);
void	storage_fill_char(t_point *storage);
void	storage_fill_string(t_point *storage, int length);
void	print_length(t_point *storage, va_list valist, int base);
intmax_t	retrieve_num(t_point *storage, va_list valist);
#endif
