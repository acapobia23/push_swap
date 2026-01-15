#include "../../includes/push_swap.h"

static void	free_one_stack(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = (*stack)->next;
	while (ptr && ptr->num != (*stack)->num)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free((*stack));
}

void	free_stack(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a))
		free_one_stack(&(*stack_a));
	if ((*stack_b))
		free_one_stack(&(*stack_b));
}

void	free_data(t_data **data)
{
	if (!data || !(*data))
		return ;
	if ((*data)->mtx)
		free_mtx((*data)->mtx);
	if ((*data)->chunks)
		free_chunks(&((*data)->chunks));
	if ((*data)->arr)
		free((*data)->arr);
	free_stack(&((*data)->stack_a), &((*data)->stack_b));
	free((*data));
}

void	error_exit(const char *str)
{
	ft_printf("%s\n",str);
	exit(1);
}

void	free_error(t_data **data, const char *str)
{
	free_data(&(*data));
	error_exit(str);
}