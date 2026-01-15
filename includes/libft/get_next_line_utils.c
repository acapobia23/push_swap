#include "get_next_line.h"

char	*extract_line_eof(char **str)
{
	char	*line;

	line = NULL;
	if (!(*str) || !(**str))
	{
		free(*str);
		(*str) = NULL;
		return (NULL);
	}
	line = ft_strdup((const char *)(*str));
	if (!line)
		return (NULL);
	free((*str));
	(*str) = NULL;
	return (line);
}
