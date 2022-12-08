#include "push_swap.h"

static size_t	get_mediane(int **tab, int size)
{
	size_t		i;
	size_t		x;
	size_t		inf;

	i = 0;
	while (i < (size_t)size)
	{
		x = 0;
		inf = 0;
		while (x < (size_t)size)
		{
			if (tab[0][x] < tab[0][i])
				inf++;
			x++;
		}
		if (size % 2 == 0 && inf * 2 == (size_t)size)
			return (i);
		else if (size % 2 == 1 && inf * 2 + 1 == (size_t)size)
			return (i);
		i++;
	}
	return (0);
}

static void		algo_simple(int **tab_a, int **tab_b, t_size *size)
{
	while (tab_sorted(tab_a, size) == 0)
	{
		while (size->a > 1)
		{
			if (tab_a[0][0] > tab_a[0][1])
				sa(tab_a, size, 0);
			pb(tab_a, tab_b, size, 0);
			if (size->b > 1 && tab_b[0][0] < tab_b[0][1])
				sb(tab_b, size, 0);
		}
		while (size->b > 0)
		{
			if (size->b > 1 && tab_b[0][0] < tab_b[0][1])
				sb(tab_b, size, 0);
			pa(tab_a, tab_b, size, 0);
			if (tab_a[0][0] > tab_a[0][1])
				sa(tab_a, size, 0);
		}
	}
}

void			push_swap_algo(int **tab_a, int **tab_b, t_size *size)
{
	size_t		i;


	algo_simple(tab_a, tab_b, size);
	i = get_mediane(tab_a, size->a);
	ft_putstr("mediane = ");
	ft_putnbr(tab_a[0][i]);
	ft_putchar('\n');
}
