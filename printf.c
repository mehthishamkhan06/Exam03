#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_putchar(int c)
{
    return(write(1, &c, 1));
}

int ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (write(1, str, i));
}

int	ft_putnbr(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
		return(ft_putstr("-2147483648"));
	if (n < 0)
	{
		length += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		length += ft_rnputnbr(n / 10);
	length += ft_putchar((n % 10) + '0');
	return (length);
}

int	ft_hex(unsigned int n)
{
	int		length;
	char	*str;

	length = 0;
	str = "0123456789abcdef";
	if (n >= 16)
		length += ft_hex(n / 16);
	length += ft_putchar(str[n % 16]);
	return (length);
}

int check_formatter(va_list args, char c)
{
    int length = 0;
    if (c == 's')
        length += ft_putstr(va_arg(args, char *));
    else if (c == 'd')
        length += ft_putnbr(va_arg(args, int));
    else if (c == 'x')
        length += ft_hex(va_arg(args, unsigned int));
    return (length);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int length = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            length += check_formatter(args, format[i]);
        }
        else
            length += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (length);
}