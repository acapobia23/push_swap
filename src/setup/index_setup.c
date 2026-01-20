#include "../../includes/push_swap.h"

static int	check_array(long *arr, int len)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	while (++i < len)
	{
		j = -1;
		count = 0;
		if (arr[i] < -2147483648 || arr[i] > 2147483647)
			return (-1);
		while (++j < len)
		{
			if (arr[j] == arr[i])
				count++;
		}
		if (count != 1)
			return (-1);
	}
	return (1);
}

static void	swap_int(long *xp, long *yp)
{
	long	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

static void	bubblesort(long *arr, int n)
{
	int		i;
	int		j;
	bool	swapped;

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
			break ;
	}
}

static long	*array_init(int len, char **mtx)
{
	long	*arr;
	int		i;

	i = -1;
	arr = NULL;
	arr = malloc(len * sizeof(long));
	if (!arr)
		return (NULL);
	while (++i < len)
		arr[i] = ft_atoi(mtx[i]);
	return (arr);
}

void	arr_index_setup(t_data **data)
{
	int	len;

	len = 0;
	while ((*data)->mtx[len])
		len++;
	(*data)->tot_n = len;
	if (len == 1)
	{
		free_data(&(*data));
		exit(1);
	}
	(*data)->arr = array_init(len, (*data)->mtx);
	if (!(*data)->arr)
		free_error(&(*data), "Error : array malloc");
	if (check_array((*data)->arr, len) == -1)
		free_error(&(*data), "Error");
	bubblesort((*data)->arr, len);
	if (!(*data)->arr)
		free_error(&(*data), "Error : array sorting fail");
}
