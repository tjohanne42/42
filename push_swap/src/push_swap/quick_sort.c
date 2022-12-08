#include "push_swap.h"

static size_t	get_mediane(int *tab, size_t start, size_t end)
{
	size_t		i;
	size_t		x;
	size_t		inf;

	i = start;
	while (i <= end)
	{
		x = start;
		inf = 0;
		while (x <= end)
		{
			if (tab[x] < tab[i])
				inf++;
			x++;
		}
		if ((end - start + 1) % 2 == 0 && inf * 2 == (end - start + 1))
			return (i);
		else if ((end - start + 1) % 2 == 1 && inf * 2 + 1 == (end - start + 1))
			return (i);
		i++;
	}
	return (0);
}

static int			quick_sort_recursif(size_t end, t_size *size, char way)
{
	int		p;
	int		mediane;
	size_t	size_max_b;
	size_t	cra;

	// way : l = left, r = right, 0 = first;
	mediane = size->tab_a[get_mediane(size->tab_a, 0, end)];
	size_max_b = size->b + ((end + 1) / 2 + 1);
	p = 0;
	cra = 0;
	while (size_max_b != (size_t)size->b)
	{
		if (size->tab_a[0] > mediane)
		{
			ra(size);
			cra++;
		}
		else if (size->tab_a[0] < mediane)
		{
			pb(size);
			p++;
		}
		else
		{
			pb(size);
			p++;
			// positionnement de la mediane dans b
			if (size->b > 1 && size_max_b != (size_t)size->b && size_max_b != (size_t)size->b - 1)
				rb(size);
		}
	}
	while (cra > 0 && way == 'l')
	{
		rra(size);
		cra--;
	}
	if (size->tab_b[1] == mediane)
		sb(size);
	else if (size->tab_b[size->b - 1] == mediane)
		rrb(size);
	return (p);
}

static size_t	part_sorted(int *a, size_t start, size_t end)
{
	while (start < end)
	{
		if (a[start] > a[start + 1])
			return (0);
		start++;
	}
	return (1);
}

static int		sort_parser(size_t end, t_size *size, char way)
{
	int		p;

	if (part_sorted(size->tab_a, 0, end) == 1)
		return (-1);
	if (size->a <= 10 && size->a + size->b >= 20)
	{
		insertion_sort(size);
		return (-1);
	}
	else if (size->a <= 5)
	{
		insertion_sort(size);
		return (-1);
	}
	p = quick_sort_recursif(end, size, way);
	return (p);
}

void			quick_sort(size_t end, t_size *size, char way)
{
	int		p;
	int		p_temp;

	if (end > 1)
	{
		p = sort_parser(end, size, way);
		if (p != -1)
		{
			quick_sort(size->a - 1, size, 'r');
			p_temp = p;
			while (p_temp > 0)
			{
				pa(size);
				p_temp--;
			}
			if (p <= 5)
				insertion_sort(size);
			else
				quick_sort(p - 1, size, 'l');
		}
	}
}
