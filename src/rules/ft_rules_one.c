#include "../../includes/rules.h"

void	ft_sa(t_stack **stack)
{
	if (ft_swap(&(*stack)) == -1)
		return ;
	else
		ft_printf("sa\n");
	return ;
}

void	ft_sb(t_stack **stack)
{
	if (ft_swap(&(*stack)) == -1)
		return ;
	else
		ft_printf("sb\n");
	return ;
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	if (ft_push(&(*stack_b), &(*stack_a)) == -1)
		return ;
	else
		ft_printf("pa\n");
	return ;
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	if (ft_push(&(*stack_a), &(*stack_b)) == -1)
		return ;
	else
		ft_printf("pb\n");
	return ;
}
