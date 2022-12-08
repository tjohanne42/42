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


void		sa(int **tab_a, t_size *size, char c)
{
	int		temp;

	if (size->a > 1)
	{
		if (c != 'm')
			ft_putstr("sa\n");
		temp = tab_a[0][0];
		tab_a[0][0] = tab_a[0][1];
		tab_a[0][1] = temp;
		size->moves++;
	}
}

void		sb(int **tab_b, t_size *size, char c)
{
	int		temp;

	if (size->b > 1)
	{
		if (c != 'm')
			ft_putstr("sb\n");
		temp = tab_b[0][0];
		tab_b[0][0] = tab_b[0][1];
		tab_b[0][1] = temp;
		size->moves++;
	}
}

void		ss(int **tab_a, int **tab_b, t_size *size, char c)
{
	sa(tab_a, size, 'm');
	sb(tab_b, size, 'm');
	if (c != 'm')
	{
		if (size->a > 1 && size->b <= 1)
			ft_putstr("sa\n");
		else if (size->b > 1 && size->a <= 1)
			ft_putstr("sb\n");
		else if (size->b > 1 && size->a > 1)
		{
			size->moves--;
			ft_putstr("ss\n");
		}
	}
}

void		pa(int **tab_a, int **tab_b, t_size *size, char c)
{
	size_t	i;

	if (size->b > 0)
	{
		if (c != 'm')
			ft_putstr("pa\n");
		i = size->a;
		while (i != 0)
		{
			tab_a[0][i] = tab_a[0][i - 1];
			i--; 
		}
		tab_a[0][0] = tab_b[0][0];
		i = 0;
		while (i < (size_t)(size->b - 1))
		{
			tab_b[0][i] = tab_b[0][i + 1];
			i++;
		}
		size->a++;
		size->b--;
		size->moves++;
	}
}

void		pb(int **tab_a, int **tab_b, t_size *size, char c)
{
	size_t	i;

	if (size->a > 0)
	{
		if (c != 'm')
			ft_putstr("pb\n");
		i = size->b;
		while (i != 0)
		{
			tab_b[0][i] = tab_b[0][i - 1];
			i--; 
		}
		tab_b[0][0] = tab_a[0][0];
		i = 0;
		while (i < (size_t)(size->a - 1))
		{
			tab_a[0][i] = tab_a[0][i + 1];
			i++;
		}
		size->a--;
		size->b++;
		size->moves++;
	}
}

void		ra(int **tab_a, t_size *size, char c)
{
	int		temp;
	size_t	i;

	if (size->a > 1)
	{
		temp = tab_a[0][0];
		i = 0;
		while (i < (size_t)(size->a - 1))
		{
			tab_a[0][i] = tab_a[0][i + 1];
			i++;
		}
		tab_a[0][size->a - 1] = temp;
		if (c != 'm')
			ft_putstr("ra\n");
		size->moves++;
	}
}

void		rb(int **tab_b, t_size *size, char c)
{
	int		temp;
	size_t	i;

	if (size->b > 1)
	{
		temp = tab_b[0][0];
		i = 0;
		while (i < (size_t)(size->b - 1))
		{
			tab_b[0][i] = tab_b[0][i + 1];
			i++;
		}
		tab_b[0][size->b - 1] = temp;
		if (c != 'm')
			ft_putstr("rb\n");
		size->moves++;
	}
}

void		rr(int **tab_a, int **tab_b, t_size *size, char c)
{
	ra(tab_a, size, 'm');
	rb(tab_b, size, 'm');
	if (c != 'm')
	{
		if (size->a > 1 && size->b <= 1)
			ft_putstr("ra\n");
		else if (size->b > 1 && size->a <= 1)
			ft_putstr("rb\n");
		else if (size->b > 1 && size->a > 1)
		{
			size->moves--;
			ft_putstr("rr\n");
		}
	}
}

void		rra(int **tab_a, t_size *size, char c)
{
	int		temp;
	size_t	i;

	if (size->a > 1)
	{
		temp = tab_a[0][size->a - 1];
		i = size->a - 1;
		while (i > 0)
		{
			tab_a[0][i] = tab_a[0][i - 1];
			i--;
		}
		tab_a[0][0] = temp;
		if (c != 'm')
			ft_putstr("rra\n");
		size->moves++;
	}
}

void		rrb(int **tab_b, t_size *size, char c)
{
	int		temp;
	size_t	i;
	
	if (size->b > 1)
	{
		temp = tab_b[0][size->b - 1];
		i = size->b - 1;
		while (i > 0)
		{
			tab_b[0][i] = tab_b[0][i - 1];
			i--;
		}
		tab_b[0][0] = temp;
		if (c != 'm')
			ft_putstr("rrb\n");
		size->moves++;
	}
}

void		rrr(int **tab_a, int **tab_b, t_size *size, char c)
{
	rra(tab_a, size, 'm');
	rrb(tab_b, size, 'm');
	if (c != 'm')
	{
		if (size->a > 1 && size->b <= 1)
			ft_putstr("rra");
		else if (size->b > 1 && size->a <= 1)
			ft_putstr("rrb");
		else if (size->a > 1 && size->b > 1)
		{
			size->moves--;
			ft_putstr("rrr");
		}
	}
}
