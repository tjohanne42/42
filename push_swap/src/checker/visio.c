#include "push_swap.h"

#define DEFAULT "\033[0m"
#define RED "\033[0;31m"
#define BOLD_RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define BOLD_GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define BOLD_YELLOW "\033[1;33m"
#define BLUE "\033[0;34m"
#define BOLD_BLUE "\033[1;34m"
#define MAGENTA "\033[0;35m"
#define BOLD_MAGENTA "\033[1;35m"
#define CYAN "\033[0;36m"
#define BOLD_CYAN "\033[1;36m"

static size_t	get_sln(t_size *size)
{
	size_t	i;
	size_t	ret;
	size_t	temp;

	i = 0;
	ret = 0;
	while (i < size->a)
	{
		temp = ft_nbrlen(size->tab_a[i]);
		if (temp > ret)
			ret = temp;
		i++;
	}
	i = 0;
	while (i < size->b)
	{
		temp = ft_nbrlen(size->tab_b[i]);
		if (temp > ret)
			ret = temp;
		i++;
	}

	return (ret);
}

static size_t	visio_pos(t_size *size, int nb)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (i < size->a)
	{
		if (size->tab_a[i] < 0 && size->tab_a[i] > nb)
			count++;
		else if (nb >= 0 && size->tab_a[i] < nb && size->tab_a[i] >= 0)
			count++;
		i++;
	}
	i = 0;
	while (i < size->b)
	{
		if (size->tab_b[i] < 0 && size->tab_b[i] > nb)
			count++;
		else if (nb >= 0 && size->tab_b[i] < nb && size->tab_b[i] >= 0)
			count++;
		i++;
	}
	return (count + 1);
}

void		visio(t_size *size, size_t try)
{
	static size_t size_largest_nb;
	size_t			i;
	size_t			temp;

	i = 0;
	if (!try)
	{
		setlocale(LC_ALL, "");
		size_largest_nb = get_sln(size);
	}
	system("clear");
	ft_putstr("A : ----------------------------\n\n");
	while (i < size->a)
	{
		ft_putnbr(size->tab_a[i]);
		temp = ft_nbrlen(size->tab_a[i]);
		while (temp <= size_largest_nb)
		{
			ft_putchar(' ');
			temp++;
		}
		temp = visio_pos(size, size->tab_a[i]);
		if (size->tab_a[i] < 0)
			ft_putstr(BOLD_RED);
		while (temp)
		{
			ft_putchar('|');
			temp--;
		}
		ft_putstr(DEFAULT);
		ft_putchar('\n');
		i++;
	}
	i = 0;
	ft_putstr("B : ----------------------------\n\n");
	while (i < size->b)
	{
		ft_putnbr(size->tab_b[i]);
		temp = ft_nbrlen(size->tab_b[i]);
		while (temp <= size_largest_nb)
		{
			ft_putchar(' ');
			temp++;
		}
		temp = visio_pos(size, size->tab_b[i]);
		if (size->tab_b[i] < 0)
			ft_putstr(BOLD_RED);
		while (temp)
		{
			ft_putchar('|');
			temp--;
		}
		ft_putstr(DEFAULT);
		ft_putchar('\n');
		i++;
	}
	system("sleep 0.02");
}
