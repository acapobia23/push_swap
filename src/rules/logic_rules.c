#include "../../includes/rules.h"

int	ft_swap(t_stack **stack)
{
	long	tmp;
	int		tmp_idx;

	tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = tmp;
	tmp_idx = (*stack)->idx;
	(*stack)->idx = (*stack)->next->idx;
	(*stack)->next->idx = tmp_idx;
	return (0);
}

int	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;
	int		count;

	if (!src || !(*src))
		return (0);
	count = count_stack((*src));
	tmp = (*src);
	if (count > 1)
	{
		(*src)->next->pre = tmp->pre;
		tmp->pre->next = tmp->next;
		(*src) = tmp->next;
	}
	else
		(*src) = NULL;
	add_on_dst(&tmp, &(*dst));
	return (0);
}

int	ft_rotate(t_stack **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return (0);
	(*stack) = (*stack)->next;
	return (0);
}

int	ft_reverse_rotate(t_stack **stack)
{
	(*stack) = (*stack)->pre;
	return (0);
}
