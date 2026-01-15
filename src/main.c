#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

    data = NULL;
	data = data_mtx_init(ac, av);
	arr_index_setup(&data);
	data->stack_a = stack_init(data);
	if (!data->stack_a)
		free_error(&data, "Error : stack_a malloc");
	chunks_setup(&data);
	if (check_order(data->stack_a, data->tot_n) == 1)
	{
		free_data(&data);
		return (0);
	}
	if (data->tot_n <= 3)
	simple_sort(&(data->stack_a), data->tot_n);
	else
	sorting_algorithms(&data);
	// print_stack(data, NULL, NULL);
	// ft_printf("\n\norder : %i\n\n", check_order(data->stack_a, data->tot_n));
	free_data(&data);
	return (0);
}
