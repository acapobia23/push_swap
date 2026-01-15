#ifndef RULES_H
# define RULES_H

#include "libft/libft.h"
#include <stdio.h>

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	tot_moves;
}		t_moves;

typedef struct s_stack
{
	int				idx;
	long			num;
	t_moves			moves;
	struct s_stack	*next;
	struct s_stack	*pre;
}		t_stack;

typedef struct s_range
{
	int	tot_n;
	int	min;
	int	max;
}		t_range;

typedef struct s_chunk
{
	struct s_chunk	*ck_high;
	t_range			high;
	t_range			mid;
	t_range			small;
}		t_chunk;

typedef struct s_data
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_chunk		*chunks;
	int			count_chunks;
	int			tot_n;
	long		*arr;
	char		**mtx;
}		t_data;

int		count_stack(t_stack *stack);
void	add_on_dst(t_stack **tmp, t_stack **dst);
int		ft_swap(t_stack **stack);
int		ft_push(t_stack **src, t_stack **dst);
int		ft_rotate(t_stack **stack);
int		ft_reverse_rotate(t_stack **stack);
void	ft_sa(t_stack **stack);
void	ft_sb(t_stack **stack);
void	ft_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_pb(t_stack **stack_b, t_stack **stack_a);
void	ft_ra(t_stack **stack);
void	ft_rb(t_stack **stack);
void	ft_rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

#endif

