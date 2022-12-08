/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 03:32:56 by tjohanne          #+#    #+#             */
/*   Updated: 2018/02/02 03:32:58 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# define BUFF_SIZE 548

typedef	struct		s_p_size
{
	int				height;
	int				right_width;
	int				left_width;
}					t_p_size;

typedef	struct		s_piece
{
	char			pos[17];
	struct s_p_size	*size;
	struct s_piece	*next;
}					t_piece;

typedef	struct		s_list
{
	size_t			lenght;
	struct s_piece	*first;
}					t_list;

typedef	struct		s_map
{
	int				size;
	char			*pos;
}					t_map;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
int					ft_sqrt_higher(int nb);
int					ft_valid_file(char *file, size_t i, size_t diese,
					size_t point);
t_list				*ft_add_piece(char *file, t_list *list);
t_p_size			*ft_size_pieces(char *tab, size_t i, size_t pos1);
void				ft_map_display(t_map *s_map);
size_t				ft_pos(size_t p, int j, size_t size);
void				ft_del_pieces(t_map *map, t_piece *piece, size_t x,
					size_t y);
int					ft_set_piece(t_map *map, t_piece *piece, size_t x,
					size_t y);
int					ft_map_resolve(t_map *map, t_piece *piece);
void				ft_resolve(t_list *list);
int					ft_insert_piece(t_list *list, char *tab, t_p_size *size);
t_list				*ft_new_list(void);
t_map				*ft_new_map(size_t size);
void				ft_free_list(t_list *list);
int					ft_diese_contact(const char *file, size_t i, size_t y,
					size_t z);

#endif
