#include "../../includes/rules.h"

int	count_stack(t_stack *stack)
{
	int		len;
	t_stack	*ptr;

	len = 1;
	if (!stack)
		return (0);
	ptr = stack->next;
	if (ptr->idx == stack->idx)
		return (len);
	while (ptr->idx != stack->idx)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}

void	add_on_dst(t_stack **tmp, t_stack **dst)
{
	if (!(*dst))
	{
		(*tmp)->next = (*tmp);
		(*tmp)->pre = (*tmp);
		(*dst) = (*tmp);
		return ;
	}
	(*tmp)->next = (*dst);
	(*tmp)->pre = (*dst)->pre;
	(*dst)->pre->next = (*tmp);
	(*dst)->pre = (*tmp);
	(*dst) = (*tmp);
}