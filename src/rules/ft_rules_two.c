#include "../../includes/rules.h"

void	ft_ra(t_stack **stack)
{
	if (ft_rotate(&(*stack)) == 0)
		ft_printf("ra\n");
	return ;
}

void	ft_rb(t_stack **stack)
{
	if (ft_rotate(&(*stack)) == 0)
		ft_printf("rb\n");
	return ;
}

void	ft_rra(t_stack **stack)
{
	if (ft_reverse_rotate(&(*stack)) == 0)
		ft_printf("rra\n");
	return ;
}

void	ft_rrb(t_stack **stack)
{
	if (ft_reverse_rotate(&(*stack)) == 0)
		ft_printf("rrb\n");
	return ;
}
