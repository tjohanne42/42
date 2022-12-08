#include "push_swap.h"
#include "time.h"
#include <stdio.h>

#define NOMBRE_MAX 50

int			rand_a_b(int a, int b)
{
	return (rand() %  (b - a) + a);
}

int			*generation_nombre(void)
{
	int			*tab;
	size_t		i;
	int			temp;
	int			temp2;

	i = 0;
	srand(time(NULL));
	if (!(tab = malloc(sizeof(*tab) * NOMBRE_MAX)))
		return (NULL);
	while (i < NOMBRE_MAX)
	{
		tab[i] = i + 1;
		if (rand() % 2 == 0)
			tab[i] *= -1;
		i++;
	}
	i = 0;
	while (i < NOMBRE_MAX)
	{
		temp = rand_a_b(0, NOMBRE_MAX);
		temp2 = tab[i];
		tab[i] = tab[temp];
		tab[temp] = temp2;
		i++;
	}
	return (tab);
}

int		main(void)
{
	int			*tab;
	size_t		i;

	i = 0;
	if (!(tab = generation_nombre()))
		return (0);
	remove("nb");
	if (!freopen("nb", "w+", stdout))
	{
		free(tab);
		return (0);
	}
	while (i < NOMBRE_MAX)
	{
		ft_putnbr(tab[i]);
		i++;
		if (i != NOMBRE_MAX)
			ft_putchar(' ');
	}
	free(tab);
	return (0);
}
