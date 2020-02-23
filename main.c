/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:22:28 by hyu               #+#    #+#             */
/*   Updated: 2020/02/06 20:29:52 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int     ft_printf(char *str, ...);

const	t_dispatch_table	*functions;

void	print_byte_hex(int	i)
{
	char hex_digits[] = "0123456789abcdef";

	//write(1, hex_digits[i / 16], 1);
	//write(1, hex_digits[i % 16], 1);
}

void    ft_putnbr_BASE(int num, int base)
{
	int		i;
	char	array[16] = "0123456789ABCDEF";
	int		remainder;

	if (num < 0)
	{
		ft_putchar('-');
		num = -1 * num;
	}
	if (num >= base)
	{
		ft_putnbr_base(num/base, base);
		remainder = num % base;
		ft_putchar(array[remainder]);
	}
	else
	{
		remainder = num % base;
		ft_putchar(array[remainder]);
	}
}

void    ft_putnbr_base(int num, int base)
{
	int		i;
	char	array[16] = "0123456789abcdef";
	int		remainder;

	if (num < 0)
	{
		ft_putchar('-');
		num = -1 * num;
	}
	if (num >= base)
	{
		ft_putnbr_base(num/base, base);
		remainder = num % base;
		ft_putchar(array[remainder]);
	}
	else
	{
		remainder = num % base;
		ft_putchar(array[remainder]);
	}
}

int		main(int argc, char **argv)
{

	//int i;
	char *str;
	short s;
	char c;
	int	i;
	long int j;
	long long int k;
	long long l;

	c = 'a';
	s = 3;
	i = 1;
	j = 10;
	k = 30;
	l = 55;

	int zipcode;

	zipcode = 9;

	printf("%03d\n", zipcode);
	printf("%05d\n", zipcode);
	ft_printf("%03d\n", zipcode);
	ft_printf("%05d\n", zipcode);
	//ft_printf("%05d", zipcode);

	//str = ft_strcpy(str, "panda");

	//ft_printf("%p\n", &i);
	//printf("%p\n", &i);
	//ft_printf("%p\n", &i);
	//ft_printf("%p", &str);
	//ft_printf("%p", 0);
	
	/*printf("%hhi\n", c);
	printf("%hi\n", s);
	printf("%li\n", j);
	printf("%lli\n", k);
	printf("%lli\n", l);
	ft_printf("%hhi\n", c);
	ft_printf("%hi\n", s);
	ft_printf("%li\n", j);
	ft_printf("%lli\n", k);
	ft_printf("%lli\n", l);*/
	/*printf("panda%*c\n", 10, 33);
	printf("panda%*c\n", 7, 36);
	printf("panda%*c\n", 2, 3);
	printf("panda%c\n", 'a');
	printf("panda%c\n", 'm');
	printf("%c\n", 20);*/
	//printf("panda%c\n", "panda");
//	printf("%s\n", "panda");
/*
	ft_printf("%c\n", 20);
	ft_printf("panda%*c\n", 10, 33);
	ft_printf("panda%*c\n", 7, 36);
	ft_printf("panda%*c\n", 2, 3);
	ft_printf("panda%c\n", 'a');
	ft_printf("panda%c\n", 'm');*/
	//printf("panda%c\n", "panda");
//	printf("%s\n", "panda");
	//ft_printf("%c\n", 20);
	//printf("panda%*X\n", 10, 33);
	//printf("panda%*X\n", 7, 36);
	//printf("%X\n", 20);
	/*printf("panda%*s\n", 10, "panda");//33);
	printf("panda%*s\n", 7, "panda");//36);
	printf("panda%*s\n", 2, "panda");//3);
	printf("panda%s\n", "panda");
	printf("panda%s\n", "panda");
	ft_printf("panda%*s\n", 10, "panda");//33);
	ft_printf("panda%*s\n", 7, "panda");//36);
	ft_printf("panda%*s\n", 2, "panda");//3);
	ft_printf("panda%s\n", "panda");
	ft_printf("panda%s\n", "panda");*/
	//ft_printf("panda%c\n", "panda");
	//ft_printf("%s\n", "panda");
	//ft_printf("%X\n", 20);
	//ft_printf("%c", 'a');
	//ft_printf("%0o\n", 1);

	//ft_putchar(functions[4].c);
	return (0);
}

//compile gcc main.c printf2.c parse.c libft/libft/libft.a check_prepend.c function_dispatch_table.c jump_table.c 
