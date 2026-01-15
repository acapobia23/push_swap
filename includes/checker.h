#ifndef CHECKER_H
# define CHECKER_H

#include "push_swap.h"

typedef struct s_funct
{
	char	*move;
	int		flag;
    void	(*one)(t_stack **stack);
    void	(*two)(t_stack **stack_a, t_stack **stack_b);
}		t_funct;

typedef struct s_checker
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_funct		*funct;
	char		**moves;
}		t_checker;

void		free_checker(t_checker **checker);
void		checker_error_free(t_checker **checker, const char *str);
t_checker	*checker_setup(int ac, char **av);
t_stack		*stack_init_checker(char **mtx);
void		add_move(char **all_moves, const char * line);
void		free_mtx(char **mtx);
void		do_moves(t_checker	**checker);
void		index_setup(t_stack **new, char **mtx);
void		check_final(t_checker *checker);
#endif