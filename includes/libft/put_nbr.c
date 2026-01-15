#include "ft_printf.h"

int	put_nbr(void *ptr, char conv)
{
	int		tot;
	char	*res;

	tot = 0;
	res = ft_itoa_base(ptr, conv);
	if (!res)
		return (0);
	tot += put_str(res);
	free(res);
	return (tot);
}

int	put_pointer(void *ptr)
{
	int				tot;
	unsigned long	num;
	char			*res;
	char			*tmp;

	tot = 0;
	if (!ptr)
		return (put_str("(nil)"));
	num = (unsigned long)ptr;
	tmp = ft_itoa_base(&num, 'p');
	if (!tmp)
		return (0);
	res = ft_strjoin("0x", (const char *)tmp);
	free(tmp);
	if (!res)
		return (0);
	tot += put_str(res);
	free(res);
	return (tot);
}
