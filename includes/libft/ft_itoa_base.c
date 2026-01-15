#include "ft_printf.h"

static char	*base_init(char c)
{
	if (c == 'i' || c == 'd' || c == 'u')
		return ("0123456789");
	else if (c == 'x' || c == 'p')
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}

static long	find_len(long num, int div)
{
	long	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num != 0)
	{
		len++;
		num /= div;
	}
	return (len);
}

static char	*str_init(int div, long num, int *i)
{
	long	len;
	char	*res;

	len = find_len(num, div);
	*i = len - 1;
	res = NULL;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (num == 0)
		res[0] = '0';
	return (res);
}

static char	*num_base(long num, char *base, int div)
{
	char	*s;
	int		i;

	s = NULL;
	s = str_init(div, num, &i);
	if (!s || num == 0)
		return (s);
	if (num < 0)
	{
		s[0] = '-';
		num *= -1;
	}
	while (num != 0)
	{
		s[i] = base[num % div];
		num /= div;
		i--;
	}
	return (s);
}

char	*ft_itoa_base(void *ptr, char conv)
{
	char	*res;
	char	*base;
	long	num;
	char	c;

	c = conv;
	base = NULL;
	base = base_init(c);
	if (c == 'd' || c == 'i')
		num = *((int *)(ptr));
	else if (c == 'X' || c == 'x' || c == 'u')
		num = *((unsigned int *)(ptr));
	else
		num = *((unsigned long *)(ptr));
	if (c == 'i' || c == 'd' || c == 'u')
		res = num_base(num, base, 10);
	else
		res = num_base(num, base, 16);
	if (!res)
		return (NULL);
	return (res);
}
