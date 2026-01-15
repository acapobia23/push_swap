#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "rules.h"

char	**mtx_init(int ac, char **av);
t_data	*data_mtx_init(int ac, char **av);
t_moves	moves_init(void);
void	free_error(t_data **data, const char *str);
void	error_exit(const char *str);
void	free_data(t_data **data);
void	free_mtx(char **mtx);
void	free_chunks(t_chunk **chunks);
void	free_stack(t_stack **stack_a, t_stack **stack_b);
void	arr_index_setup(t_data **data);
t_stack	*stack_init(t_data *data);
void	chunks_setup(t_data **data);
int	    check_order(t_stack *stack, int tot_n);
void	simple_sort(t_stack **stack, int tot_n);
void	sorting_algorithms(t_data **data);
void	set_cost_moves(t_stack **stack_b, t_stack *stack_a, t_data **data);
void	set_moves(t_stack *trg_a, t_stack **trg_b, t_data *data);
t_stack	*find_cheapest(t_stack *stack, int len);
int	    same_verse(t_stack *cheap);
void	push_cheapest(t_data **data, t_stack *cheap);
t_stack	*find_small(t_stack *stack);
void	take_on_top_smaller(t_stack **stack_a);
int	    distance_from_top(t_stack *trg, t_stack *head);
void	put_pos_single(t_stack **stack, int i, int c, int verse, int flag);
t_stack	*find_big(t_stack *stack);
t_stack	*find_target(int idx, t_stack *stack, int max_idx);
#endif