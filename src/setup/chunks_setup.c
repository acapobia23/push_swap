#include "../../includes/push_swap.h"

static t_range	make_range(int start, int end)
{
	t_range	new;

	new.min = start;
	if (end)
	new.max = end;
	new.tot_n = (end - start) + 1;
	return (new);
}

static t_chunk	*new_chunk(int	num_tot, int start, int end_final)
{
	t_chunk	*new;
	int	size;
	int	end;

	if (num_tot <= 3)
		size = num_tot / 1;
	if (num_tot > 3 && num_tot <= 5)
		size = num_tot / 2;
	else
		size = num_tot / 3;
	new = NULL;
	new = malloc(sizeof(t_chunk));
	if (!new)
		return (NULL);
	end = start + size;
	new->small = make_range(start, end);
	start = end + 1;
	end = start + size;
	if (num_tot > 3)
	new->mid = make_range(start, end);
	start = end + 1;
	end = end_final;
	new->high = make_range(start, end);
	new->ck_high = NULL;
	return (new);
}

static void	divide_high_range(t_data **data)
{
	t_chunk	*ptr;
	int		tmp;
	long	next_high;

	tmp = (*data)->chunks->high.tot_n;
	ptr = (*data)->chunks;
	ptr->ck_high = new_chunk(tmp, ptr->high.min, ptr->high.max);
	if (!((*data)->chunks->ck_high))
		free_error(&(*data), "Error : fist chunk divide failure");
	next_high = 1;
	while (++next_high < (*data)->count_chunks)
	{
		ptr->ck_high = new_chunk(ptr->high.tot_n, ptr->high.min, ptr->high.max);
		if (!ptr->ck_high)
			free_error(&(*data), "Error : chunk divide failure");
		ptr = ptr->ck_high;
	}
}

void	chunks_setup(t_data **data)
{
	int count;
	int size;

	size = (*data)->tot_n;
	count = 0;
	while (size > 3)
	{
		size = (size + 2) / 3;
		count++;
	}
	if ((*data)->tot_n <= 3)
		return ;
	(*data)->count_chunks = count;
	(*data)->chunks = new_chunk((*data)->tot_n, 0, (*data)->tot_n);
	if (!(*data)->chunks)
		free_error(&(*data), "Error : chunks malloc");
	if ((*data)->count_chunks > 1)
		divide_high_range(&(*data));
}
