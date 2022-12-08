#include "push_swap.h"

size_t	ra(t_size *size)
{
	int		tmp;
	size_t	i;

	if (size->a > 1)
	{
		i = 0;
		tmp = size->tab_a[0];
		while (i < size->a - 1)
		{
			size->tab_a[i] = size->tab_a[i + 1];
			i++;
		}
		size->tab_a[i] = tmp;
	}
	if (!(insert_tab_ops(size, 6)))
		return (0);
	return (1);
}

size_t	rb(t_size *size)
{
	int		tmp;
	size_t	i;

	if (size->b > 1)
	{
		i = 0;
		tmp = size->tab_b[0];
		while (i < size->b - 1)
		{
			size->tab_b[i] = size->tab_b[i + 1];
			i++;
		}
		size->tab_b[i] = tmp;
	}
	if (!(insert_tab_ops(size, 7)))
		return (0);
	return (1);
}

size_t	rr(t_size *size)
{
	ra(size);
	rb(size);
	size->pos_ops -= 2;
	if (!(insert_tab_ops(size, 8)))
		return (0);
	return (1);	
}

size_t	rra(t_size *size)
{
	int		tmp;
	size_t	i;

	if (size->a > 1)
	{
		i = size->a - 1;
		tmp = size->tab_a[i];
		while (i > 0)
		{
			size->tab_a[i] = size->tab_a[i - 1];
			i--;
		}
		size->tab_a[0] = tmp;
	}
	if (!(insert_tab_ops(size, 9)))
		return (0);
	return (1);
}

size_t	rrb(t_size *size)
{
	int		tmp;
	size_t	i;

	if (size->b > 1)
	{
		i = size->b - 1;
		tmp = size->tab_b[i];
		while (i > 0)
		{
			size->tab_b[i] = size->tab_b[i - 1];
			i--;
		}
		size->tab_b[0] = tmp;
	}
	if (!(insert_tab_ops(size, 10)))
		return (0);
	return (1);
}
