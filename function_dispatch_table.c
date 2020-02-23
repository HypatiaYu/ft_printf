#include "printf.h"

void	assign_tpoint(char *str, int *i, t_point *storage, va_list valist)
{
	check_flags(str, i, storage, valist);
	check_width(str, i, storage, valist);
	check_precisions(str, i, storage, valist);
	check_length(str, i, storage);
}

void	printf_character(t_point *storage, va_list valist)
{
	int	specifier;
	intmax_t		i;
	char c;

	specifier = storage->flags;
	i = va_arg(valist, int);
	c = (char)i;
	if (storage->alignment == 1)
	{
		print_prepend(storage);
		storage_fill_char(storage);
		ft_putchar(i);
	}
	if (storage->alignment == 0)
	{
		storage_fill_char(storage);
		print_prepend(storage);
		ft_putchar(i);
	}
}


void	printf_integer_8(t_point *storage, va_list valist)
{
	int	specifier;
	char	*str;
	intmax_t		i;
	
	specifier = storage->flags;
	i = retrieve_num(storage, valist);
	if (storage->alignment == 1)
	{
		print_prepend(storage);
		storage_fill_int(storage, 8, i);
		ft_putnbr_base(i, 8);
	}
	if (storage->alignment == 0)
	{
		storage_fill_int(storage, 8, i);
		print_prepend(storage);
		ft_putnbr_base(i, 8);
	}
}

void	printf_integer_10(t_point *storage, va_list valist)
{
	int	specifier;
	int	i;
	char *str;

	specifier = storage->flags;
	i = retrieve_num(storage, valist);
	if (storage->alignment == 1)
	{
		print_prepend(storage);
		storage_fill_int(storage, 10, i);
		ft_putnbr_base(i, 10);
	}
	if (storage->alignment == 0)
	{
		storage_fill_int(storage, 10, i);
		print_prepend(storage);
		ft_putnbr_base(i, 10);
	}
}

void	printf_integer_16(t_point *storage, va_list valist)
{
	int	specifier;
	int	i;

	specifier = storage->flags;
	i = retrieve_num(storage, valist);
	if (storage->alignment == 1)
	{
		print_prepend(storage);
		storage_fill_int(storage, 16, i);
		ft_putnbr_base(i, 16);
	}
	if (storage->alignment == 0)
	{
		storage_fill_int(storage, 16, i);
		print_prepend(storage);
		ft_putnbr_base(i, 16);
	}
}

void	printf_INT_16(t_point *storage, va_list valist)
{
	int	specifier;
	int	i;
	int	j;

	specifier = storage->flags;
	j = 0;
	i = retrieve_num(storage, valist);
	if (storage->alignment == 1)
	{
		print_prepend(storage);
		storage_fill_int(storage, 16, i);
		ft_putnbr_BASE(i, 16);
	}
	if (storage->alignment == 0)
	{
		storage_fill_int(storage, 16, i);
		print_prepend(storage);
		ft_putnbr_BASE(i, 16);
	}
}

void		print_string(t_point *storage, va_list valist)
{
	int	specifier;
	char *str;
	int length;

	specifier = storage->flags;
	str = va_arg(valist, char *);	
	length = ft_strlen(str);
	if (storage->alignment == 1)
	{
		print_prepend(storage);
		storage_fill_string(storage, length);
		ft_putstr(str);
	}
	if (storage->alignment == 0)
	{
		storage_fill_string(storage, length);
		print_prepend(storage);
		ft_putstr(str);
	}
}

void		print_string_int(t_point *storage, va_list valist)
{
	int	specifier;
	int	*str;
	int	j;
	int	length;

	length = 0;
	specifier = storage->flags;
	j = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	str = va_arg(valist, int *);
	while (j < 6)
	{
		print_byte_hex((int)str[j]);
		j++;
	}
	if (storage->alignment == 1)
	{
		print_prepend(storage);
		storage_fill_string(storage, length);
	}
	if (storage->alignment == 0)
	{
		storage_fill_string(storage, length);
		print_prepend(storage);	
	}		
}
