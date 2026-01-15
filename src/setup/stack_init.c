#include "../../includes/push_swap.h"

int	check_order(t_stack *stack, int tot_n)
{
	int		i;
	t_stack	*ptr;

	i = -1;
	ptr = stack;
	while (++i < tot_n && ptr->next != stack)
	{
		if (ptr->idx > ptr->next->idx)
			return (-1);
		ptr = ptr->next;
	}
	return (1);
}
t_moves	moves_init(void)
{
	t_moves	new;

	new.ra = 0;
	new.rb = 0;
	new.rra = 0;
	new.rrb = 0;
	new.tot_moves = 0;
	return (new);
}

static int	find_idx(long num, long *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (num == arr[i])
			return (i);
		i++;
	}
	return (i);
}

static t_stack	*new_value(char *value, t_data *data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->pre = NULL;
	new->num = ft_atoi((const char *)value);
	new->idx = find_idx(new->num, data->arr, data->tot_n);
	new->moves = moves_init();
	return (new);
}

t_stack	*stack_init(t_data *data)
{
	t_stack	*new;
	t_stack	*ptr;
	int		i;

	i = 0;
	new = NULL;
	new = new_value(data->mtx[i], data);
	ptr = new;
	while (data->mtx[++i])
	{
		ptr->next = new_value(data->mtx[i], data);
		if (!ptr->next)
		{
			free_stack(&new, NULL);
			return (NULL);
		}
		ptr->next->pre = ptr;
		ptr = ptr->next;
	}
	new->pre = ptr;
	ptr->next = new;
	return (new);
}
