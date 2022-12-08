#include "push_swap.h"

static size_t	insert_tab_ops_2(t_size *size, int **tmp)
{
	size_t	i;

	i = 0;
	free(size->ops);
	size->ops = NULL;
	size->size_ops *= 2;
	if (!(size->ops = malloc(sizeof(int) * size->size_ops)))
		return (0);
	while (i < size->pos_ops)
	{
		size->ops[i] = tmp[0][i];
		i++;
	}
	return (1);
}

size_t	insert_tab_ops(t_size *size, size_t value)
{
	int		*tmp;
	size_t	i;

	if (size->pos_ops == size->size_ops)
	{
		i = 0;
		if (!(tmp = malloc(sizeof(int) * size->size_ops)))
			return (0);
		while (i < size->pos_ops)
		{
			tmp[i] = size->ops[i];
			i++;
		}
		if (!insert_tab_ops_2(size, &tmp))
			return (0);
		free(tmp);
		tmp = NULL;
	}
	size->ops[size->pos_ops] = value;
	size->pos_ops++;
	return (1);
}

size_t	algo_completed(t_size *size)
{
	size_t	i;

	i = 0;
	if (size->b != 0)
		return (0);
	while (i < size->a - 1)
	{
		if (size->tab_a[i] > size->tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

size_t	rrr(t_size *size)
{
	rra(size);
	rrb(size);
	size->pos_ops -= 2;
	if (!(insert_tab_ops(size, 11)))
		return (0);
	return (1);	
}
