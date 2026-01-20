#include "../includes/push_swap.h"

static void	compare_cheap(t_stack **cheap, t_stack **ptr)
{
	int	cheap_idx;
	int	curr_idx;

	if ((*cheap) == (*ptr))
		return ;
	cheap_idx = (*cheap)->idx;
	curr_idx = (*ptr)->idx;
	if (curr_idx > cheap_idx)
		(*cheap) = (*ptr);
}

t_stack	*find_cheapest(t_stack *stack, int len)
{
	t_stack	*ptr;
	t_stack	*cheap;
	int		i;

	i = -1;
	cheap = stack;
	ptr = stack;
	while (++i < len)
	{
		if (ptr->moves.tot_moves < cheap->moves.tot_moves)
			cheap = ptr;
		else if (ptr->moves.tot_moves == cheap->moves.tot_moves)
			compare_cheap(&cheap, &ptr);
		ptr = ptr->next;
	}
	return (cheap);
}

t_stack	*find_big(t_stack *stack)
{
	t_stack	*ptr;
	t_stack	*big;
	int		i;
	int		len;

	len = count_stack(stack);
	i = -1;
	ptr = stack;
	big = stack;
	while (++i < len)
	{
		if (ptr->idx > big->idx)
			big = ptr;
		ptr = ptr->next;
	}
	return (big);
}

t_stack	*find_target(int idx, t_stack *stack, int max_idx)
{
	t_stack	*ptr;
	int		len;
	int		i;
	int		trg_idx;

	ptr = stack;
	len = count_stack(stack);
	trg_idx = idx + 1;
	while (trg_idx <= max_idx)
	{
		ptr = stack;
		i = -1;
		while (++i < len)
		{
			if (ptr->idx == trg_idx)
				return (ptr);
			ptr = ptr->next;
		}
		trg_idx++;
	}
	return (ptr);
}

void	set_cost_moves(t_stack **stack_b, t_stack *stack_a, t_data **data)
{
	t_stack	*target;
	t_stack	*ptr;
	int		i;
	int		len;

	ptr = (*stack_b);
	len = count_stack((*stack_b));
	i = -1;
	while (++i < len)
	{
		ptr->moves = moves_init();
		target = find_target(ptr->idx, stack_a, (*data)->tot_n - 1);
		set_moves(target, &ptr, (*data));
		ptr = ptr->next;
	}
}
