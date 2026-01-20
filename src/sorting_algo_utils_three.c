#include "../includes/push_swap.h"

t_stack	*find_small(t_stack *stack)
{
	t_stack	*ptr;
	t_stack	*small;

	ptr = stack->next;
	small = stack;
	while (ptr->idx != stack->idx)
	{
		if (ptr->idx < small->idx)
			small = ptr;
		ptr = ptr->next;
	}
	return (small);
}

static int	is_consec(t_data **data, t_chunk *ptr, int *count_pb, int tot_push)
{
	int	idx_a;
	int	idx_b;

	idx_a = (*data)->stack_a->idx;
	idx_b = (*data)->stack_b->idx;
	if ((*count_pb) == tot_push)
		return (-1);
	else if (count_stack((*data)->stack_a) <= 3)
		return (-1);
	else if ((idx_a + 1) == idx_b || (idx_a - 1) == idx_b)
	{
		if (ft_ischunk(idx_a, ptr, (*data)->tot_n))
			return (1);
	}
	else if ((idx_a + 2) == idx_b || (idx_a - 2) == idx_b)
	{
		if (ft_ischunk(idx_a, ptr, (*data)->tot_n))
			return (1);
	}
	return (-1);
}

void	push_consevutive(t_data **data, t_chunk *ptr, int *count_pb,\
						int tot_push)
{
	while (is_consec(&(*data), ptr, &(*count_pb), tot_push) == 1)
	{
		ft_pb(&((*data)->stack_b), &((*data)->stack_a));
		(*count_pb)++;
	}
}
