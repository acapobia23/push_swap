#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_checker	*checker;

	checker = checker_setup(ac, av);
	if (checker->moves)
	{
		if (check_moves(checker->moves, checker->funct) == -1)
			checker_error_free(&checker, "Error");
		do_moves(&checker);
	}
	check_final(checker);
	free_checker(&checker);
	return (0);
}
