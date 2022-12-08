#include "push_swap.h"

static size_t		small_sort_3(t_size *size)
{
	if (size->a > 3)
		return (0);
	if (size->a == 2 || size->a == 1)
	{
		if (size->a != 1 && size->tab_a[0] > size->tab_a[1])
			sa(size);
		return (1);
	}
	if (size->tab_a[0] < size->tab_a[1] && size->tab_a[1] < size->tab_a[2])
		return (1);
	if (size->tab_a[0] > size->tab_a[1] && size->tab_a[0] > size->tab_a[2])
		ra(size);
	if ((size->tab_a[2] < size->tab_a[0] && size->tab_a[0] < size->tab_a[1]) ||
	 	(size->tab_a[0] < size->tab_a[2] && size->tab_a[2] < size->tab_a[1]))
	 	rra(size);
	if (size->tab_a[0] > size->tab_a[1])
		sa(size);
	return (1);
}

static t_insert		*find_y(t_size *size)
{
	t_insert	*insert;
	int			min;
	int			max;
	int			way_a;
	int			way_b;
	size_t		i;

	i = 0;
	insert = NULL;
	if (!(insert = malloc(sizeof(*insert))))
		return (NULL);
	insert->min = 0;
	insert->max = 0;
	way_a = 0;
	while (i < size->a)
	{
		min = i;
		max = i + 1;
		if (max == (int)size->a)
			max = 0;
		while (size->tab_a[i] < size->tab_a[max])
		{
			i++;
			max++;
			if ((size_t)max == size->a)
				max = 0;
			else if (i == size->a)
				i = 0;
		}
		max--;
		if (max == -1)
			max = size->a - 1;
		if (min <= max)
			way_b = max - min;
		else
			way_b = size->a - min + max;
		if (way_b > way_a)
		{
			insert->min = min;
			insert->max = max;
			way_a = way_b;
		}
		i = min + 1;
	}
	if (insert->min == 0 && insert->max == 0)
	{
		sa(size);
		insert->max = 1;
	}
	return (insert);
}

static size_t	all_sort(t_size *size, t_insert *insert)
{
	if ((insert->min == 0 && insert->max == (int)size->a - 1) || (insert->min != 0 && insert->min - 1 == insert->max))
		return (1);
	return (0);
}

static int		find_c(t_size *size, t_insert *insert)
{
	int		i;

	if (insert->min < insert->max && insert->min > 0)
		return (0);
	i = 0;
	while (1)
	{
		if ((i < insert->min && insert->min < insert->max) || (i > insert->max && insert->max > insert->min) ||
			(i < insert->min && insert->min > insert->max && i > insert->max))
			return (i);
		if (((int)size->a - 1 - i < insert->min && insert->min < insert->max) || ((int)size->a - 1 - i > insert->max && insert->max > insert->min) ||
			((int)size->a - 1 - i < insert->min && insert->min > insert->max && (int)size->a - 1 - i > insert->max))
			return ((int)size->a - 1 - i);
		i++;
	}
}

static size_t	find_d(t_size *size, t_insert *insert)
{
	size_t	i;

	i = 0;
	if (size->tab_a[0] < size->tab_a[insert->min])
		return (insert->min - 1);
	else if (size->tab_a[0] > size->tab_a[insert->max])
		return (insert->max);
	while (i < size->a)
	{
		if ((int)i >= insert->min && (int)i <= insert->max && size->tab_a[0] > size->tab_a[i] && size->tab_a[0] < size->tab_a[i + 1])
			return (i);
		i++;
	}
	return (0);
}

static size_t	put_c_into_y(t_size *size, t_insert *insert, int c)
{
	int		ra_ptr;
	int		rra_ptr;
	size_t	d;
	size_t	way[4];


	// verifier que c est mal placé
	if (size->tab_a[c] < size->tab_a[insert->min] && (c + 1 == insert->min || (c + 1 == (int)size->a && insert->min == 0)))
		return (0);
	else if (size->tab_a[c] > size->tab_a[insert->max] && (c - 1 == insert->max || (c - 1 == -1 && insert->max == 0)))
		return (0);
	// mettre c au debut de a
	ra_ptr = c;
	rra_ptr = size->a - c;
	if (ra_ptr <= rra_ptr)
	{
		while (c != 0)
		{
			ra(size);
			insert->min--;
			insert->max--;
			c--;
			if (insert->min == -1)
				insert->min = size->a - 1;
			if (insert->max == -1)
				insert->max = size->a - 1;
		}
	}
	else
	{
		while (c != 0)
		{
			rra(size);
			insert->min++;
			insert->max++;
			c++;
			if (c == (int)size->a)
				c = 0;
			if (insert->min == (int)size->a)
				insert->min = 0;
			if (insert->max == (int)size->a)
				insert->max = 0;
		}
	}
	// les plus simples deplacements
	if (insert->min < insert->max && insert->min == 1 && size->tab_a[0] > size->tab_a[1] && size->tab_a[0] < size->tab_a[2])
	{
		sa(size);
		return (0);
	}
	else if (insert->max == (int)size->a - 1 && insert->min < insert->max && size->tab_a[0] < size->tab_a[size->a - 1] && size->tab_a[0] > size->tab_a[size->a - 2])
	{
		rra(size);
		sa(size);
		return (0);
	}
	// d est la position voulue dans y
	d = find_d(size, insert);
	// way sont les deplacements possibles
	// way[0] = rra sa
	// way[1] = sa ra sa
	// way[2] = pb ra ra pa
	// way[3] = pb rra pa
	way[0] = (size->a - d - 1) * 2;
	way[1] = (d - 1) * 2 + 1;
	way[2] = d + 2;
	way[3] = size->a - d + 1;
	if (way[0] <= way[1] && way[0] <= way[2] && way[0] <= way[3])
	{
		while (way[0] > 0)
		{
			rra(size);
			sa(size);
			way[0] -= 2;
		}
	}
	else if (way[1] <= way[0] && way[1] <= way[2] && way[1] <= way[3])
	{
		while (way[1] > 0)
		{
			sa(size);
			way[1]--;
			if (way[1] > 0)
			{
				ra(size);
				way[1]--;
			}
		}
	}
	else if (way[2] <= way[0] && way[2] <= way[1] && way[2] <= way[3])
	{
		pb(size);
		while (way[2] > 2)
		{
			ra(size);
			way[2]--;
		}
		pa(size);
	}
	else
	{
		pb(size);
		while (way[3] > 2)
		{
			rra(size);
			way[3]--;
		}
		pa(size);
	}
	return (0);
}

size_t		insertion_sort(t_size *size)
{
	t_insert	*insert;

	if (small_sort_3(size) == 1)
		return (1);
	insert = NULL;
	if (!(insert = find_y(size)))
		return (0);
	while (all_sort(size, insert) == 0)
	{
		// y is the longuest part of a already sort, stocked in insert
		// c is the pos of nearest number not in y
		put_c_into_y(size, insert, find_c(size, insert));
		free(insert);
		if (!(insert = find_y(size)))
			return (0);
	}
	// start remettre dans l'ordre
	int		ra_ptr;
	int		rra_ptr;
	ra_ptr = insert->min;
	rra_ptr = size->a - insert->min + 1;
	if (ra_ptr <= rra_ptr)
	{
		while (insert->min != 0)
		{
			ra(size);
			insert->min--;
			insert->max--;
			if (insert->min == -1)
				insert->min = size->a - 1;
			if (insert->max == -1)
				insert->max = size->a - 1;
		}
	}
	else
	{
		while (insert->min != 0)
		{
			rra(size);
			insert->min++;
			insert->max++;
			if (insert->min == (int)size->a)
				insert->min = 0;
			if (insert->max == (int)size->a)
				insert->min = 0;
		}
	}
	
	// end remettre dans l'ordre
	free(insert);
	return (1);
}
