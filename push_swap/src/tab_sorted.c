#include "push_swap.h"

size_t				tab_sorted(int **tab_a, t_size *size)
{
	size_t		i;

	if (size->b > 0 || size->a == 0)
		return (0);
	else if (size->a == 1)
		return (1);
	i = 0;
	while (i < (size_t)(size->a - 1))
	{
		if (tab_a[0][i] > tab_a[0][i + 1])
			return (0);
		i++;
	}
	return (1);
}
