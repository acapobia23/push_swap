#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_checker	*checker;

	checker = checker_setup(ac, av);
	if (checker->moves)
	{
		if (ft_strncmp("Error", (const char *)checker->moves[0], 5) == 0)
			checker_error_free(&checker, "Error");
		do_moves(&checker);
	}
	check_final(checker);
	free_checker(&checker);
	return (0);
} 
