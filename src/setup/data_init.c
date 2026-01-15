#include "../../includes/push_swap.h"

static int	check_args(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (ft_isdigit(args[i][j]) == 0)
			{
				if (args[i][j] == '-')
				{
					if (ft_isdigit(args[i][j + 1]) == 0)
						return (-1);
				}
				else
					return (-1);
			}
		}
		
	}
	return (0);
}

char	**mtx_copy(char **av)
{
	char	**mtx;
	int		len;
	int		i;

	len = 0;
	if (!av)
		return (NULL);
	while (av[len])
		len++;
	mtx = NULL;
	mtx = ft_calloc((len + 1), sizeof(char *));
	if (!mtx)
		return (NULL);
	i = -1;
	while (av[++i])
	{
		mtx[i] = ft_strdup((const char *)av[i]);
		if (!mtx[i])
		{
			free_mtx(mtx);
			return (NULL);
		}
	}
	mtx[i] = NULL;
	return (mtx);
}

char	**mtx_init(int ac, char **av)
{
	char	**mtx;

	mtx = NULL;
	if (ac == 2)
		mtx = ft_split((char const *)av[1], ' ');
	else
		mtx = mtx_copy(av + 1);
	if (!mtx)
		return (NULL);
	return (mtx);
}

static t_data	*data_init(void)
{
	t_data	*new;

	new = NULL;
	new = ft_calloc(1, sizeof(t_data));
	if (!new)
		return (NULL);
	new->mtx = NULL;
	new->stack_a = NULL;
	new->stack_b = NULL;
	new->chunks = NULL;
	new->arr = NULL;
	new->tot_n = 0;
	new->count_chunks = 0;
	return (new);
}

t_data	*data_mtx_init(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac == 1)
		exit(1);
	data = data_init();
	if (!data)
		error_exit("Error : data malloc");
	data->mtx = mtx_init(ac, av);
	if (!data->mtx)
		free_error(&data, "Error : mtx malloc");
	if (check_args(data->mtx) == -1)
		free_error(&data, "Error");
	return (data);
}
