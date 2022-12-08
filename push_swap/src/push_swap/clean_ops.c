#include "push_swap.h"

static size_t	last_valid(t_size *size, int i)
{
	if (i <= 0)
		return (0);
	while (i > 0 && size->ops[i] == 0)
		i--;
	return ((size_t)i);
}

static size_t		clean_ops_4(int *i, size_t *temp, t_size *size)
{
	if ((size->ops[*temp] == 7 && size->ops[*i] == 11) || (size->ops[*temp] == 11 && size->ops[*i] == 7))
	{
		size->ops[*temp] = 0;
		size->ops[*i] = 9;
		*temp = last_valid(size, *i - 1);
		*i -= 1;
	}
	else if ((size->ops[*temp] == 9 && size->ops[*i] == 8) || (size->ops[*temp] == 8 && size->ops[*i] == 9))
	{
		size->ops[*temp] = 0;
		size->ops[*i] = 7;
		*temp = last_valid(size, *i - 1);
		*i -= 1;
	}
	else if ((size->ops[*temp] == 10 && size->ops[*i] == 8) || (size->ops[*temp] == 8 && size->ops[*i] == 10))
	{
		size->ops[*temp] = 0;
		size->ops[*i] = 6;
		*temp = last_valid(size, *i - 1);
		*i -= 1;
	}
	else
		return (0);
	return (1);
}

static size_t		clean_ops_3(int *i, size_t *temp, t_size *size)
{
	if ((size->ops[*temp] == 6 && size->ops[*i] == 7) || (size->ops[*temp] == 7 && size->ops[*i] == 6))
	{
		size->ops[*temp] = 0;
		size->ops[*i] = 8;
		*temp = last_valid(size, *i - 1);
		*i -= 1;
	}
	else if ((size->ops[*temp] == 9 && size->ops[*i] == 10) || (size->ops[*temp] == 10 && size->ops[*i] == 9))
	{
		size->ops[*temp] = 0;
		size->ops[*i] = 11;
		*temp = last_valid(size, *i - 1);
		*i -= 1;
	}
	else if ((size->ops[*temp] == 6 && size->ops[*i] == 11) || (size->ops[*temp] == 11 && size->ops[*i] == 6))
	{
		size->ops[*temp] = 0;
		size->ops[*i] = 10;
		*temp = last_valid(size, *i - 1);
		*i -= 1;
	}
	else
		return (clean_ops_4(i, temp, size));
	return (1);
}

static size_t		clean_ops_2(int *i, size_t *temp, t_size *size)
{
	if ((size->ops[*temp] == 1 && size->ops[*i] == 2) || (size->ops[*temp] == 2 && size->ops[*i] == 1))
	{
		size->ops[*temp] = 0;
		size->ops[*i] = 3;
		*temp = last_valid(size, *i - 1);
		*i -= 1;
	}
	else if ((size->ops[*temp] == 1 && size->ops[*i] == 3) || (size->ops[*temp] == 3 && size->ops[*i] == 1))
	{
		size->ops[*temp] = 0;
		size->ops[*i] = 2;
		*temp = last_valid(size, *i - 1);
		*i -= 1;
	}
	else if ((size->ops[*temp] == 2 && size->ops[*i] == 3) || (size->ops[*temp] == 3 && size->ops[*i] == 2))
	{
		size->ops[*temp] = 0;
		size->ops[*i] = 1;
		*temp = last_valid(size, *i - 1);
		*i -= 1;
	}
	else
		return (clean_ops_3(i, temp, size));
	return (1);
}

void	clean_ops(t_size *size)
{
	int		i;
	size_t	temp;

	i = 1;
	temp = 0;
	while (i < (int)size->pos_ops)
	{
		if ((size->ops[temp] == 1 && size->ops[i] == 1) || (size->ops[temp] == 2 && size->ops[i] == 2) ||
			(size->ops[temp] == 4 && size->ops[i] == 5) || (size->ops[temp] == 5 && size->ops[i] == 4) ||
			(size->ops[temp] == 6 && size->ops[i] == 9) || (size->ops[temp] == 9 && size->ops[i] == 6) ||
			(size->ops[temp] == 7 && size->ops[i] == 10) || (size->ops[temp] == 10 && size->ops[i] == 7) ||
			(size->ops[temp] == 8 && size->ops[i] == 11) || (size->ops[temp] == 11 && size->ops[i] == 8) ||
			(size->ops[temp] == 3 && size->ops[i] == 3))
		{
			size->ops[temp] = 0;
			size->ops[i] = 0;
			temp = last_valid(size, i - 1);
		}
		else if (!clean_ops_2(&i, &temp, size))
		{
			if (size->ops[i] != 0)
				temp = i;
		}
		i++;
	}
}
