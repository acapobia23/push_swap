#include "../includes/push_swap.h"

void	take_on_top_smaller(t_stack **stack_a)
{
	t_stack	*ptr;
	int	ra;
	int	rra;
	int	c;

	ra = 0;
	rra = 0;
	c = 0;
	ptr = find_small((*stack_a));
	ra =  distance_from_top(ptr, (*stack_a));
	rra = count_stack((*stack_a)) - ra;
	if (ra < rra)
		put_pos_single(&(*stack_a), c, ra, 1, 0);
	else
		put_pos_single(&(*stack_a), c, rra, 2, 0);
}

static void	sort_case_4(t_stack **stack)
{
	ft_sa(&(*stack));
	ft_ra(&(*stack));
}

static void	sort_case_2(t_stack **stack)
{
	ft_sa(&(*stack));
	ft_rra(&(*stack));
}

void	simple_sort(t_stack **stack, int tot_n)
{
	int	first;
	int	second;
	int	third;

	if (tot_n == 2)
	{
		if ((*stack)->idx > (*stack)->next->idx)
			ft_sa(&(*stack));
		return ;
	}
	first = (*stack)->idx;
	second = (*stack)->next->idx;
	third = (*stack)->next->next->idx;
	if (first > second && second < third && third > first)
		ft_sa(&(*stack));
	else if (first > second && second > third && third < first)
		sort_case_2(&(*stack));
	else if (first > second && second < third && third < first)
		ft_ra(&(*stack));
	else if (first < second && second > third && third > first)
		sort_case_4(&(*stack));
	else if (first < second && second > third && third < first)
		ft_rra(&(*stack));
}
