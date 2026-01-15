#include "../includes/checker.h"

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