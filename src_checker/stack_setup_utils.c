#include "../includes/checker.h"

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

static void	swap_int(long* xp, long* yp)
{
	long	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

static void bubbleSort(long *arr, int n)
{
	int	i;
	int	j;
	bool swapped;

	i = -1;
	while (++i < n)
	{
		j = -1;
		swapped = false;
		while (++j < n - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap_int(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

static long	*array_init(int len, char **mtx)
{
	long	*arr;
	int	i;

	i = -1;
	arr = NULL;
	arr = malloc(len * sizeof(long));
	if (!arr)
		return (NULL);
	while (++i < len)
		arr[i] = ft_atoi(mtx[i]);
	return (arr);
}

void	index_setup(t_stack **new, char **mtx)
{
	t_stack	*ptr;
	long	*arr;
	int		i;
	int		len;

	len = 0;
	i = -1;
	ptr = (*new);
	while (mtx[len])
		len++;
	arr = array_init(len, mtx);
	if (!arr)
		return ;
	 bubbleSort(arr, len);
	 while (++i < len)
	 {
		ptr->idx = find_idx(ptr->num, arr, len);
		ptr = ptr->next;
	 }
	 free(arr);
}
