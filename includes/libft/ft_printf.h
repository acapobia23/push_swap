#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		put_pointer(void *ptr);
char	*ft_itoa_base(void *ptr, char conv);
int		put_nbr(void *ptr, char conv);
int		put_char(char c);
int		put_str(char *s);
#endif
