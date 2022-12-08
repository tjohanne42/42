#include "push_swap.h"

static size_t	check_double(t_size *size)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i != size->a - 1)
	{
		j = 1;
		while (i + j != size->a)
		{
			if (size->tab_a[i] == size->tab_a[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static size_t	put_nb_2(char *argv, size_t j, size_t z, size_t *t, t_size *size)
{
	intmax_t	temp;

	if ((argv[j] >= '0' && argv[j] <= '9') || ((argv[j + 1] >= '0' &&
		argv[j + 1] <= '9') && (argv[j] == '+' || argv[j] == '-')))
	{
		temp = ft_atoimax(&argv[z]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (0);
		size->tab_a[*t] = ft_atoi(&argv[z]);
		*t += 1;
	}
	return (1);
}

static size_t	put_nb(int argc, char **argv, t_size *size, size_t i)
{
	size_t		j;
	size_t		t;
	size_t		z;

	t = 0;
	while ((int)i++ != argc - 1)
	{
		z = 0;
		j = 0;
		while (argv[i][j] != '\0')
		{
			while ((argv[i][z] > 8 && argv[i][z] < 14) || argv[i][z] == 32)
				z++;
			j = z;
			if (!(put_nb_2(argv[i], j, z, &t, size)))
				return (0);
			while ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			z = j;
		}
	}
	return (1);
}

static int		count_nb(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	count = 0;
	while ((int)i++ != argc - 1)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && (argv[i][j] <= 8 || argv[i][j] >= 14)
				&& argv[i][j] != 32 && argv[i][j] != '+' && argv[i][j] != '-')
				return (-1);
			while ((argv[i][j] > 8 && argv[i][j] < 14) || argv[i][j] == 32)
				j++;
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (argv[i][j + 1] < '0' || argv[i][j + 1] > '9')
					return (-1);
				j++;
			}
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				count++;
			while (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
		}
	}
	return (count);
}

t_size			*check_arg(int argc, char **argv)
{
	t_size		*size;
	int			count;

	if (argc < 2)
		return (NULL);
	size = NULL;
	if ((count = count_nb(argc, argv)) == -1)
		return (NULL);
	if (!(size = malloc(sizeof(*size))))
		return (NULL);
	if (!(size->tab_a = malloc(sizeof(int) * count)))
		return (NULL);
	if (!(size->tab_b = malloc(sizeof(int) * count)))
		return (NULL);
	size->a = (size_t)count;
	size->b = 0;
	if (!(put_nb(argc, argv, size, 0)))
		return (NULL);
	if (!(check_double(size)))
		return (NULL);
	size->size_ops = count * 3;
	if (!(size->ops = malloc(sizeof(size_t) * size->size_ops)))
		return (NULL);
	size->pos_ops = 0;
	return (size);
}
