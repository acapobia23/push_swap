#include "../includes/checker.h"

void	add_move(char **all_moves, const char *line)
{
	char	*tmp;

	tmp = NULL;
	if (line == NULL)
		return ;
	tmp = ft_strjoin((const char *)(*all_moves), line);
	free((*all_moves));
	(*all_moves) = NULL;
	if (!tmp)
		return ;
	(*all_moves) = tmp;
}

static t_moves	moves_init_ck(void)
{
	t_moves	new;

	new.ra = 0;
	new.rb = 0;
	new.rra = 0;
	new.rrb = 0;
	new.tot_moves = 0;
	return (new);
}

static t_stack	*new_value_ck(char *value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->pre = NULL;
	new->num = ft_atoi((const char *)value);
	new->idx = 0;
	new->moves = moves_init_ck();
	return (new);
}

t_stack	*stack_init_checker(char **mtx)
{
	t_stack	*new;
	t_stack	*ptr;
	int		i;

	i = 0;
	new = NULL;
	new = new_value_ck(mtx[i]);
	ptr = new;
	while (mtx[++i])
	{
		ptr->next = new_value_ck(mtx[i]);
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
	index_setup(&new, mtx);
	return (new);
}
