#include "printf.h"

void	check_flags(char *str, int *i, t_point *character, va_list valist)
{
	int	j;
	if (str[*i] == '-')
		character->alignment = 1;
	if (str[*i] == '+' || str[*i] == '0' || str[*i] == '#')
		character->alignment = 0;

	if (str[*i] == '-' || str[*i] == '+')
		character->fill = 0;
	/*fill with 0's */
	if (str[*i] == '0' || str[*i] == '#')
	{
		character->fill = 1;
		j = va_arg(valist, int);
		character->width = j;
	}
	/* add a plus */
	if (str[*i] == '+')
	{
		character->prepend = 1;
		character->prepend_number = 0;
	}
	else if (str[*i] == ' ')
	{
		character->prepend = 2;
		character->prepend_number = 0;
	}
	else if (str[*i] == '0')
	{
		character->prepend = 3;
		if (str[*i + 1] <= '9' && str[*i + 1] >= '0')
			character->prepend_number = ft_atoi(&str[*i + 1]);
	}
	else
	{
		character->prepend = 0;	
		character->prepend_number = 0;
	}
	if (str[*i] == '-'|| str[*i] == '+'|| str[*i] == ' '||
		str[*i] == '#')
		*i = *i + 1;
	else if (str[*i] == '0' && (str[*i + 1] <= '9' && str[*i + 1] >= '0'))
		*i = *i + 2;
	else if (str[*i] == '0' && (str[*i + 1] > '9' && str[*i + 1] < '0'))
		*i = *i + 1; 
	/*make a data structure to change the padding */
}

void	check_width(char *str, int *i, t_point *character, va_list valist)
{
	int	j;
	if (str[*i] == '*')
	{
		j = va_arg(valist, int);
		character->width  = j;
		*i = *i + 1;
		character->total_num = character->total_num + 1;
	}
	//ft_putnbr(j);
}

void     check_precisions(char *str, int *i, t_point *character, va_list valist)
{
	int j;
	if (str[*i] == '.' || (str[*i] == '0' && str[*i + 1] == '.'))
	{
		if (str[*i] == '0')
			*i = *i + 1;
		if (str[*i] == '.')
			*i = *i + 1;
		if (str[*i] == '*')
		{
			j = va_arg(valist, int);
			character->precision = j;
			*i = *i + 1;
			//character->total_num = character->total_num + 1;
		}
		if (str[*i] <= '9' &&
		str[*i] >= '0')
		{
			j = ft_atoi(&str[*i]);
			character->precision = j;
			*i = *i + 1;
		}
	}
	return;
}

void		check_length(char *str, int *i, t_point *character)
{
	if (str[*i] == 'h' && str[*i + 1] == 'h') 
		character->length = 0;
	if (str[*i] == 'h' && str[*i + 1] != 'h')
		character->length = 1;
    if (str[*i] == 'l' && str[*i + 1] != 'l')
		character->length = 2;
    if (str[*i] == 'l' && str[*i + 1] == 'l')
		character->length = 3;
    if (str[*i] == 'L')
		character->length = 4;
	if ((str[*i] == 'h' && str[*i + 1] != 'h') ||
		(str[*i] == 'l' && str[*i + 1] != 'l' ) ||
		str[*i] == 'L')
		*i = *i + 1;
	if ((str[*i] == 'h' && str[*i + 1] == 'h') ||
		(str[*i] == 'l' && str[*i + 1] == 'l'))
		*i = *i + 2;
}