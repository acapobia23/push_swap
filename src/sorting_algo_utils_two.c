#include "../includes/push_swap.h"

static int	verse_return(t_moves moves, t_moves tmp)
{
	int	verse;

	verse = 0;
	if ((tmp.ra == 1 && tmp.rb == 1))
		verse = 1;
	else if ((tmp.rra == 1 && tmp.rrb == 1))
		verse = 2;
	else if (tmp.ra == 0 && moves.ra != 0)
	{
		if (moves.rb <= moves.rrb)
			verse = 1;
		else
			verse = 2;
	}
	else if (tmp.rb == 0 && moves.rb != 0)
	{
		if (moves.ra <= moves.rra)
			verse = 1;
		else
			verse = 2;
	}
	return (verse);
}

int	same_verse(t_stack *cheap)
{
	t_moves	tmp;

	tmp.ra = -1;
	tmp.rb = -1;
	tmp.rra = -1;
	tmp.rrb = -1;
	if (cheap->moves.ra < cheap->moves.rra)
		tmp.ra = 1;
	else if (cheap->moves.ra > cheap->moves.rra)
		tmp.rra = 1;
	else if (cheap->moves.ra == cheap->moves.rra)
		tmp.ra = 0;
	if (cheap->moves.rb < cheap->moves.rrb)
		tmp.rb = 1;
	else if (cheap->moves.rb > cheap->moves.rrb)
		tmp.rrb = 1;
	else if (cheap->moves.rb == cheap->moves.rrb)
		tmp.rb = 0;
	return (verse_return(cheap->moves, tmp));
}

static void	set_tot_moves(t_moves *moves)
{
	if (moves->ra <= moves->rra)
		moves->tot_moves += moves->ra;
	else
		moves->tot_moves += moves->rra;
	if (moves->rb <= moves->rrb)
		moves->tot_moves += moves->rb;
	else
		moves->tot_moves += moves->rrb;
}

int	distance_from_top(t_stack *trg, t_stack *head)
{
	t_stack	*ptr;
	int		pos;

	ptr = head;
	pos = 0;
	while (ptr->idx != trg->idx)
	{
		pos++;
		ptr = ptr->next;
	}
	return (pos);
}

void	set_moves(t_stack *trg_a, t_stack **trg_b, t_data *data)
{
	int	size_a;
	int	size_b;

	size_a = count_stack(data->stack_a);
	size_b = count_stack(data->stack_b);
	(*trg_b)->moves.ra = distance_from_top(trg_a, data->stack_a);
	(*trg_b)->moves.rb = distance_from_top((*trg_b), data->stack_b);
	(*trg_b)->moves.rra = size_a - (*trg_b)->moves.ra;
	(*trg_b)->moves.rrb = size_b - (*trg_b)->moves.rb;
	set_tot_moves(&((*trg_b)->moves));
}
