#include "../../includes/push_swap.h"

void	free_chunks(t_chunk **chunks)
{
	t_chunk	*ptr;
	t_chunk	*tmp;

	ptr = (*chunks)->ck_high;
	while (ptr)
	{
		tmp = ptr->ck_high;
		free(ptr);
		ptr = tmp;
	}
	free((*chunks));
}

void	free_mtx(char **mtx)
{
	int	i;

	i = -1;
	if (!mtx)
		return ;
	while (mtx[++i])
		free(mtx[i]);
	free(mtx);
}