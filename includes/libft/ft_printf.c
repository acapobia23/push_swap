#include "ft_printf.h"

int	put_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		put_char(s[i]);
		i++;
	}
	return (i);
}

int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	print_arg(va_list args, char conv)
{
	int	tot;
	int	n;

	tot = 0;
	if (conv == 'c')
		tot += put_char(va_arg(args, int));
	else if (conv == 's')
		tot += put_str(va_arg(args, char *));
	else if (conv == 'p')
		tot += put_pointer((void *)(va_arg(args, unsigned long)));
	else if (conv == 'i' || conv == 'd')
	{
		n = va_arg(args, int);
		tot += put_nbr((void *)&n, conv);
	}
	else if (conv == 'u' || conv == 'x' || conv == 'X')
	{
		n = va_arg(args, unsigned int);
		tot += put_nbr((void *)&n, conv);
	}
	else if (conv == '%')
		tot += put_char('%');
	return (tot);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		tot;

	i = 0;
	tot = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			tot += print_arg(args, format[i]);
		}
		else
			tot += put_char(format[i]);
		i++;
	}
	va_end(args);
	return (tot);
}
