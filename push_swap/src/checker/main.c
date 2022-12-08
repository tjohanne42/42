#include "push_swap.h"

static size_t	read_instruction(t_size *size, size_t v)
{
	char		*line;
	size_t		b;

	b = 0;
	line = NULL;
	if (v == 1)
		visio(size, 0);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "sa"))
			sa(size);
		else if (!ft_strcmp(line, "sb"))
			sb(size);
		else if (!ft_strcmp(line, "ss"))
			ss(size);
		else if (!ft_strcmp(line, "pa"))
			pa(size);
		else if (!ft_strcmp(line, "pb"))
			pb(size);
		else if (!ft_strcmp(line, "ra"))
			ra(size);
		else if (!ft_strcmp(line, "rb"))
			rb(size);
		else if (!ft_strcmp(line, "rr"))
			rr(size);
		else if (!ft_strcmp(line, "rra"))
			rra(size);
		else if (!ft_strcmp(line, "rrb"))
			rrb(size);
		else if (!ft_strcmp(line, "rrr"))
			rrr(size);
		else
		{
			free(line);
			return (0);
		}
		free(line);
		if (v == 1)
			visio(size, b);
		if (!b)
			b++;
		if (algo_completed(size) == 1)
			return (1);
	}
	free(line);
	return (1);
}

static size_t	find_v(int argc, char **argv)
{
	size_t	i;
	size_t	z;
	size_t	len;
	size_t	ret;

	i = 1;
	ret = 0;
	while ((int)i < argc)
	{
		len = ft_strlen(argv[i]);
		if (len > 1)
		{
			z = 0;
			while (z < len - 1)
			{
				if (argv[i][z] == '-' && argv[i][z + 1] == 'v')
				{
					if (argv[i][z + 2] != '\0')
					{
						argv[i][z++] = ' ';
						argv[i][z] = ' ';
					}
					else
					{
						z = len - 2;
						argv[i][z] = '\0';
					}
					ret = 1;
				}
				z++;
			}
		}
		i++;
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	t_size	*size;
	size_t	v;

	if (argc < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	size = NULL;
	v = find_v(argc, argv);
	if (!(size = check_arg(argc, argv)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (read_instruction(size, v))
	{
		if (algo_completed(size) == 1)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	else
		ft_putstr("Error\n");
	free(size->ops);
	free(size->tab_a);
	free(size->tab_b);
	free(size);
	return (0);
}