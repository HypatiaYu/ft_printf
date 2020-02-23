#include "printf.h"

const	t_dispatch_table	*functions;

int     ft_printf(char *str, ...)
{
	int	i;
	va_list valist;
	t_point *storage;
	int		j;
	
	i = 0;
	j = 0;
	storage = (t_point*)malloc(sizeof(t_point*));		
	t_dispatch_table functions[] = 
	{
		{'c', printf_character},
		{'p', print_string_int},
  		{'d', printf_integer_10},
		{'i', printf_integer_10},
		{'u', printf_integer_10},
		{'o', printf_integer_8},
		{'x', printf_integer_16},
		{'s', print_string},
		{'X', printf_INT_16}
	};
	storage->total_num = 0;
	va_start(valist, str);
    while (str[i])
    {
		default_settings(storage);
        str_scan(str, &i, storage);
		if (is_percentage(str[i]) == 0)
        {
            i = i + 1;
			storage->total_num = storage->total_num + 1;
			assign_tpoint(str, &i, storage, valist);
			while (functions[j].c != 0)
			{
				if (functions[j].c == str[i])
				{
					storage->total_num = storage->total_num + 1;
					functions[j].function(storage, valist);
					i = i + 1;
				}
				j++;
			}
        }
    }
	free (storage);
    va_end(valist);
    return (0);
}
