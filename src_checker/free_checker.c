#include "../includes/checker.h"

int	check_moves(char **moves, t_funct *funct)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strncmp("Error", (const char *)moves[0], 5) == 0)
		return (-1);
	while (moves[i])
	{
		j = -1;
		while (++j < 11)
		{
			if (ft_mystrcmp(moves[i], funct[j]) == 1)
				break ;
		}
		if (j == 11)
			return (-1);
		i++;
	}
	return (0);	
}

void	free_checker(t_checker **checker)
{
	int	i;

	i = -1;
	while (++i < 11)
		free((*checker)->funct[i].move);
	free_stack(&((*checker)->stack_a), &((*checker)->stack_b));
	free((*checker)->funct);
	free_mtx((*checker)->moves);
	free((*checker));
}

void	checker_error_free(t_checker **checker, const char *str)
{
	free_checker(&(*checker));
	error_exit(str);
}