#include "push_swap.h"

size_t		algo(t_size *size)
{
	if (algo_completed(size) == 1)
		return (1);
	quick_sort(size->a - 1, size, 0);
	if (size->a == 2)
		insertion_sort(size);
	return (1);
}
