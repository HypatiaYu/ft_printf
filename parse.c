#include "printf.h"

void    str_scan(const char *str, int *i, t_point *storage)
{

    while (str[*i] && str[*i] != '%')
    {
        ft_putchar(str[*i]);
        *i = *i + 1;
        storage->total_num = storage->total_num + 1;
    }
}

int     digits_base(int n, int base)
{
    int i;
    i = 0;
    while (n != 0)
    {
        n = n / base;
        i++;
    }
    return (i);
}

int     is_percentage(char c)
{
    if (c == '\0')
        return (-1);
    if (c == '%')
        return (0);
    return (1);
}

void    default_settings(t_point *storage)
{
    storage->alignment = 1;
    storage->width = 0;
    storage->fill = 0;
    storage->prepend = 0;
    storage->prepend_number = 0;
    storage->length = 0;
    storage->base = 10;
    storage->string = 0;
    storage->int_char = 0;
    storage->precision = 1;
}