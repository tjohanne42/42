#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
#include <locale.h>

typedef struct 	s_size
{
	int			*ops;
	size_t		pos_ops;
	size_t		size_ops;
	size_t		a;
	size_t		b;
	int			*tab_a;
	int			*tab_b;
}				t_size;

typedef struct 	s_insert
{
	int			min;
	int			max;
	// min et max sont des positions
}				t_insert;

t_size		*check_arg(int argc, char **argv);
void		clean_ops(t_size *size);
size_t		algo(t_size *size);
size_t		algo_completed(t_size *size);
size_t		insertion_sort(t_size *size);
void		quick_sort(size_t end, t_size *size, char way);
void		visio(t_size *size, size_t try);


// start ops
size_t		insert_tab_ops(t_size *size, size_t value);
size_t		sa(t_size *size);
size_t		sb(t_size *size);
size_t		ss(t_size *size);
size_t		pa(t_size *size);
size_t		pb(t_size *size);
size_t		ra(t_size *size);
size_t		rb(t_size *size);
size_t		rr(t_size *size);
size_t		rra(t_size *size);
size_t		rrb(t_size *size);
size_t		rrr(t_size *size);
// end ops
#endif