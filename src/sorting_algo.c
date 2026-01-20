#include "../includes/push_swap.h"

int	ft_ischunk(int idx, t_chunk *ptr, int max_idx)
{
	if (idx >= (max_idx - 3))
		return (-1);
	else if (idx >= ptr->high.min && idx <= ptr->high.max)
		return (-1);
	return (1);
}

static void	push_mid_small(t_data **data, t_chunk *ptr, int *count_pb,\
		int tot_push)
{
	ft_pb(&((*data)->stack_b), &((*data)->stack_a));
	(*count_pb)++;
	push_consevutive(&(*data), ptr, &(*count_pb), tot_push);
	if ((*count_pb) < tot_push && count_stack((*data)->stack_a) > 3)
	{
		if (ft_ischunk((*data)->stack_a->idx, ptr, (*data)->tot_n) == -1
			&& (*data)->stack_b->idx <= ptr->small.max)
			ft_rr(&((*data)->stack_a), &((*data)->stack_b));
		else if ((*data)->stack_b->idx <= ptr->small.max)
			ft_rb(&((*data)->stack_b));
	}
}

static void	push_chunks(t_data **data, t_stack **stack_a)
{
	t_chunk	*ptr;
	int		count_pb;
	int		c;
	int		tot_push;

	count_pb = 0;
	ptr = (*data)->chunks;
	tot_push = ptr->small.tot_n + ptr->mid.tot_n;
	c = count_stack(*stack_a);
	while (ptr && (c > 3 && check_order((*stack_a), c) != 1))
	{
		if (ft_ischunk((*stack_a)->idx, ptr, (*data)->tot_n) == 1)
			push_mid_small(&(*data), ptr, &count_pb, tot_push);
		else
			ft_ra(&(*stack_a));
		if (count_pb == tot_push)
		{
			ptr = ptr->ck_high;
			if (ptr)
				tot_push = ptr->small.tot_n + ptr->mid.tot_n;
			count_pb = 0;
		}
		c = count_stack(*stack_a);
	}
}

static void	push_back(t_data **data)
{
	t_stack	*cheap;
	int		i;
	int		len;

	i = -1;
	len = count_stack((*data)->stack_b);
	cheap = NULL;
	while (++i < len && (*data)->stack_b != NULL)
	{
		set_cost_moves(&(*data)->stack_b, (*data)->stack_a, &(*data));
		cheap = find_cheapest((*data)->stack_b, count_stack((*data)->stack_b));
		push_cheapest(&(*data), cheap);
		cheap = NULL;
	}
}

void	sorting_algorithms(t_data **data)
{
	push_chunks(&(*data), &((*data)->stack_a));
	if (check_order((*data)->stack_a, count_stack((*data)->stack_a)) == -1)
	{
		while (count_stack((*data)->stack_a) > 3)
			ft_pb(&((*data)->stack_b), &((*data)->stack_a));
		simple_sort(&((*data)->stack_a), 3);
	}
	push_back(&(*data));
	take_on_top_smaller(&((*data)->stack_a));
}
