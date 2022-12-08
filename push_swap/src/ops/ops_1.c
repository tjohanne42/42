#include "push_swap.h"

/*
SWAP
sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
rien s’il n’y en a qu’un ou aucun.

sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait
rien s’il n’y en a qu’un ou aucun.

ss : sa et sb en même temps.

!! ex : tab[0] <=> tab[1]    sommet = tab[0]

PUSH
pa : push a - prend le premier élément au sommet de b et le met sur a. Ne fait
rien si b est vide.

pb : push b - prend le premier élément au sommet de a et le met sur b. Ne fait
rien si a est vide.

!! ex : a[0] = b[0]    sommet = tab[0]

ROTATE
ra : rotate a - décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.

rb : rotate b - décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.

rr : ra et rb en même temps.

!! ex : a[1] = a[0]    a[0] = a[MAX]

REVERSE ROTATE
rra : reverse rotate a - décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.

rrb : reverse rotate b - décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.

rrr : rra et rrb en même temps.

!! ex : a[0] = a[1]    a[MAX] = a[0]
*/

size_t	sa(t_size *size)
{
	int		tmp;

	if (size->a > 1)
	{
		tmp = size->tab_a[0];
		size->tab_a[0] = size->tab_a[1];
		size->tab_a[1] = tmp;
	}
	if (!(insert_tab_ops(size, 1)))
		return (0);
	return (1);
}

size_t	sb(t_size *size)
{
	int		tmp;

	if (size->b > 1)
	{
		tmp = size->tab_b[0];
		size->tab_b[0] = size->tab_b[1];
		size->tab_b[1] = tmp;
	}
	if (!(insert_tab_ops(size, 2)))
		return (0);
	return (1);
}

size_t	ss(t_size *size)
{
	int		tmp;

	if (size->a > 1)
	{
		tmp = size->tab_a[0];
		size->tab_a[0] = size->tab_a[1];
		size->tab_a[1] = tmp;
	}
	if (size->b > 1)
	{
		tmp = size->tab_b[0];
		size->tab_b[0] = size->tab_b[1];
		size->tab_b[1] = tmp;
	}
	if (!(insert_tab_ops(size, 3)))
		return (0);
	return (1);
}

size_t	pa(t_size *size)
{
	size_t	i;

	if (size->b > 0)
	{
		i = size->a;
		while (i > 0)
		{
			size->tab_a[i] = size->tab_a[i - 1];
			i--;
		}
		size->tab_a[0] = size->tab_b[0];
		i = 0;
		while (i < size->b - 1)
		{
			size->tab_b[i] = size->tab_b[i + 1];
			i++;
		}
		size->b--;
		size->a++;
	}
	if (!(insert_tab_ops(size, 4)))
		return (0);
	return (1);
}

size_t	pb(t_size *size)
{
	size_t	i;

	if (size->a > 0)
	{
		i = size->b;
		while (i > 0)
		{
			size->tab_b[i] = size->tab_b[i - 1];
			i--;
		}
		size->tab_b[0] = size->tab_a[0];
		i = 0;
		while (i < size->a - 1)
		{
			size->tab_a[i] = size->tab_a[i + 1];
			i++;
		}
		size->a--;
		size->b++;
	}
	if (!(insert_tab_ops(size, 5)))
		return (0);
	return (1);
}