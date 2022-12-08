#include "push_swap.h"

static	void	print_ops(t_size *size)
{
	size_t	i;

	i = 0;
	while (i < size->pos_ops)
	{
		if (size->ops[i] == 1)
			ft_putstr("sa\n");
		else if (size->ops[i] == 2)
			ft_putstr("sb\n");
		else if (size->ops[i] == 3)
			ft_putstr("ss\n");
		else if (size->ops[i] == 4)
			ft_putstr("pa\n");
		else if (size->ops[i] == 5)
			ft_putstr("pb\n");
		else if (size->ops[i] == 6)
			ft_putstr("ra\n");
		else if (size->ops[i] == 7)
			ft_putstr("rb\n");
		else if (size->ops[i] == 8)
			ft_putstr("rr\n");
		else if (size->ops[i] == 9)
			ft_putstr("rra\n");
		else if (size->ops[i] == 10)
			ft_putstr("rrb\n");
		else if (size->ops[i] == 11)
			ft_putstr("rrr\n");
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_size	*size;

	if (argc < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	size = NULL;
	if (!(size = check_arg(argc, argv)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	algo(size);
	clean_ops(size);
	print_ops(size);
	free(size->ops);
	free(size->tab_a);
	free(size->tab_b);
	free(size);
	return (0);
}