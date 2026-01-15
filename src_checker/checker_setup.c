#include "../includes/checker.h"

static t_funct new_rule(const char *move, int flag, void (*one)(t_stack **stack), void (*two)(t_stack **stack_a, t_stack **stack_b))
{
	t_funct	new;

	new.one = one;
	new.two = two;
	new.flag = flag;
	new.move = ft_strdup(move);
	return (new);
}

static t_funct	*funct_setup(void)
{
	t_funct	*new;

	new = NULL;
	new = malloc(11 * sizeof(t_funct));
	if (!new)
		return (NULL);
	new[0] = new_rule("ra", 0, ft_ra, NULL);
	new[1] = new_rule("rra", 0, ft_rra, NULL);
	new[2] = new_rule("rb", 0, ft_rb, NULL);
	new[3] = new_rule("rrb", 0, ft_rrb, NULL);
	new[4] = new_rule("rrr", 1, NULL, ft_rrr);
	new[5] = new_rule("rr", 1, NULL, ft_rr);
	new[6] = new_rule("ss", 1, NULL, ft_ss);
	new[7] = new_rule("sb", 0, ft_sb, NULL);
	new[8] = new_rule("sa", 0, ft_sa, NULL);
	new[9] = new_rule("pa", 1, NULL, ft_pa);
	new[10] = new_rule("pb", 1, NULL, ft_pb);
	return (new);
}

static char	**read_moves(void)
{
	char	**mtx;
	char	*line;
	char	*all_moves;

	mtx = NULL;
	line = NULL;
	all_moves = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line || (ft_strlen(line) == 1 && line[0] == '\n'))
		{
			if (line)
				free(line);
			break;
		}
		add_move(&all_moves, (const char *)line);
		free(line);
	}
	if (!all_moves)
		return (NULL);
	mtx = ft_split(all_moves, '\n');
	if (all_moves)
		free(all_moves);
	return (mtx);
}

t_checker	*checker_setup(int ac, char **av)
{
	t_checker	*new;
	char		**mtx;

	new = NULL;
	new = malloc(sizeof(t_checker));
	if (!new)
	return (NULL);
	new->stack_b = NULL;
	new->stack_a = NULL;
	new->moves = NULL;
	new->moves = read_moves();
	mtx = NULL;
	mtx = mtx_init(ac, av);
	if (!mtx)
		checker_error_free(&new, "mtx error\n");
	new->stack_a = stack_init_checker(mtx);
	free_mtx(mtx);
	new->funct = funct_setup();
	if (!new->funct || !new->stack_a)
		checker_error_free(&new, NULL);
	return (new);
}
