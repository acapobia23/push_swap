#include "../includes/checker.h"

void	check_final(t_checker *checker)
{
	int		flag;
	int		len;
	t_stack	*ptr;

	if (!checker->stack_a || checker->stack_b)
	{
		ft_printf("KO\n");
		return ;
	}
	len = count_stack(checker->stack_a);
	flag = 0;
	ptr = checker->stack_a;
	while (--len != 0)
	{
		if (ptr->idx > ptr->next->idx)
			flag = 1;
		ptr = ptr->next;
	}
	if (flag == 1)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int	ft_mystrcmp(char *moves, t_funct funct)
{
	int	i;

	i = 0;
	while (moves[i] && funct.move[i])
	{
		if (moves[i] != funct.move[i])
			return (-1);
		i++;
	}
	if (funct.move[i] != '\0' || moves[i] != '\0')
		return (-1);
	return (1);
}

static void	two_stacks(t_checker **checker, t_funct *funct)
{
	if (funct->move[0] == 'p')
		funct->two(&((*checker)->stack_b), &((*checker)->stack_a));
	else
		funct->two(&((*checker)->stack_a), &((*checker)->stack_b));
}

static void	one_stack(t_checker **checker, t_funct *funct)
{
	if (ft_strrchr((const char *)funct->move, 'a'))
		funct->one(&((*checker)->stack_a));
	else
		funct->one(&((*checker)->stack_b));
}

void	do_moves(t_checker	**checker)
{
	int	i;
	int	j;

	i = 0;
	while ((*checker)->moves[i])
	{
		j = -1;
		while (++j < 11)
		{
			if (ft_mystrcmp((*checker)->moves[i], (*checker)->funct[j]) == 1)
			{
				if ((*checker)->funct[j].flag == 0)
					one_stack(&(*checker), &((*checker)->funct[j]));
				else
					two_stacks(&(*checker), &((*checker)->funct[j]));
				break ;
			}
		}
		if (j == 11)
			break ;
		i++;
	}
}
