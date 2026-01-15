#include "../includes/push_swap.h"

static void	set_count(int *c_a, int *c_b, t_stack *cheap, int verse)
{
	if (verse == 1)
	{
		(*c_a) = cheap->moves.ra;
		(*c_b) = cheap->moves.rb;
	}
	else
	{
		(*c_a) = cheap->moves.rra;
		(*c_b) = cheap->moves.rrb;
	}
}

void	put_pos_single(t_stack **stack, int i, int c, int verse, int flag)
{
	if (flag == 0)
	{
		while (i < c)
		{
			if (verse == 1)
				ft_ra(&(*stack));
			else
				ft_rra(&(*stack));
			i++;
		}
	}
	else
	{
		while (i < c)
		{
			if (verse == 1)
				ft_rb(&(*stack));
			else
				ft_rrb(&(*stack));
			i++;
		}
	}
}
static void	put_pos_same_verse(t_data **data, t_stack *cheap, int verse)
{
	int	i;
	int	c_a;
	int	c_b;

	i = 0;
	set_count(&c_a, &c_b, cheap, verse);
	while (i < c_a && i < c_b)
	{
		if (verse == 1)
			ft_rr(&(*data)->stack_a, &(*data)->stack_b);
		else
			ft_rrr(&(*data)->stack_a, &(*data)->stack_b);
		i++;
	}
	if (i < c_a)
		put_pos_single(&((*data)->stack_a), i, c_a, verse, 0);
	if (i  < c_b)
		put_pos_single(&((*data)->stack_b), i, c_b, verse, 1);
	if ((*data)->stack_b->idx != cheap->idx)
		put_pos_single(&((*data)->stack_b), i, c_b + 1, verse, 1);
}

static void	put_pos_alone(t_data **data, t_stack *cheap)
{
	int	c_a;
	int	c_b;
	int	i;

	i = 0;
	if (cheap->moves.ra <= cheap->moves.rra)
		c_a = cheap->moves.ra;
	else
		c_a = cheap->moves.rra;
	if (cheap->moves.rb <= cheap->moves.rrb)
		c_b = cheap->moves.rb;
	else
		c_b = cheap->moves.rrb;
	if (cheap->moves.ra <= cheap->moves.rra)
		put_pos_single(&((*data)->stack_a), i, c_a, 1, 0);
	else
		put_pos_single(&((*data)->stack_a), i, c_a, 2, 0);
	if (cheap->moves.rb < cheap->moves.rrb)
		put_pos_single(&((*data)->stack_b), i, c_b, 1, 1);
	else
		put_pos_single(&((*data)->stack_b), i, c_b, 2, 1);
}

void	push_cheapest(t_data **data, t_stack *cheap)
{
	int	verse;

	verse = same_verse(cheap);
	if (verse > 0)
		put_pos_same_verse(&(*data), cheap, verse);
	else
		put_pos_alone(&(*data), cheap);
	ft_pa(&((*data)->stack_b), &((*data)->stack_a));
}
