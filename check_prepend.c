#include "printf.h"


void    storage_fill(t_point *storage)
{
    if (storage->fill == 0)
		ft_putchar(' ');
    else if (storage->fill == 1)
		ft_putchar('0');
}

void    print_prepend(t_point *storage)
{
    int l;

    l = 0;
    if (storage->prepend == 1)
		ft_putchar('+');
	if (storage->prepend == 2)
		ft_putchar(' ');
    if (storage->prepend == 3)
	{
		ft_putchar('0');
		/*
		ft_putnbr(storage->prepend_number);
		while (l < storage->width - storage->prepend_number)
		{
			ft_putchar('0');
			l++;
		}*/
	}
}

void	storage_fill_int(t_point *storage, int base, int i)
{
	int	k;
	int	j;
	j = 0;
	if (storage->prepend != 0)
		k = 1;
	else
		k = 0;	
	while (j < storage->width - k - digits_base(i, base) - storage->prepend_number)
	{
		storage_fill(storage);
		j++;
	}
}

void	storage_fill_char(t_point *storage)
{
	int	k;
	int	j;
	j = 0;
	if (storage->prepend != 0)
		k = 1;
	else
		k = 0;	
	while (j < storage->width - k - 1)
	{
		storage_fill(storage);
		j++;
	}
}

void	storage_fill_string(t_point *storage, int length)
{
	int	j;
	int k;

	j = 0;
	if (storage->prepend != 0)
		k = 1;
	else
		k = 0;
	while (j < storage->width - k - length)
	{
		storage_fill(storage);
		j++;
	}
}

intmax_t	retrieve_num(t_point *storage, va_list valist)
{
	intmax_t	i;
	
	if (storage->length == 0)
		i = (char)va_arg(valist, int);
	if (storage->length == 1)
		i = (short)va_arg(valist, int);
	if (storage->length == 2)
		i = (long)va_arg(valist, long int);
	if (storage->length == 3)
		i = (long long)va_arg(valist, long long int);
	i = (intmax_t)i;
	return (i);
}