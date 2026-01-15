#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

char	*get_next_line(int fd);
int		check_str(char *str);
char	*extract_line(char **str);
int		new_call(char **str, int fd);
char	*extract_line_eof(char **str);

#endif