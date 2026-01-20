#include "../../includes/rules.h"

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_swap(&(*stack_a)) == 0 || ft_swap(&(*stack_b)) == 0)
		ft_printf("ss\n");
	return ;
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_rotate(&(*stack_a)) == 0 && ft_rotate(&(*stack_b)) == 0)
		ft_printf("rr\n");
	return ;
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(&(*stack_b));
	ft_reverse_rotate(&(*stack_a));
	ft_printf("rrr\n");
	return ;
}
