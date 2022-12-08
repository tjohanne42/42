/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:31:06 by tjohanne          #+#    #+#             */
/*   Updated: 2018/01/19 17:31:07 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

size_t	ft_pos(size_t p, int j, size_t size)
{
	if (p % 4 > (j + p) % 4)
		return (((p + j) / 4 - p / 4) * size - (4 - j % 4));
	if (p % 4 < (j + p) % 4)
		return (((p + j) / 4 - p / 4) * size + j % 4);
	return (((p + j) / 4 - p / 4) * size);
}

void	ft_del_pieces(t_map *map, t_piece *piece, size_t x, size_t y)
{
	size_t	p;
	size_t	j;

	j = 0;
	p = 0;
	while (piece->pos[p] == '.')
		p++;
	while (piece->pos[p + j] != '\0')
	{
		if (piece->pos[p + j] != '.')
			map->pos[y + (x * map->size) + ft_pos(p, j, map->size)] = '.';
		j++;
	}
}

int		ft_set_piece(t_map *map, t_piece *piece, size_t x, size_t y)
{
	size_t	p;
	int		j;
	size_t	validate;

	validate = 0;
	j = 0;
	p = 0;
	while (piece->pos[p] == '.')
		p++;
	while (piece->pos[p + j] != '\0')
	{
		if (piece->pos[p + j] != '.' && map->pos[y + (x * map->size) +
			ft_pos(p, j, map->size)] != '.')
			return (0);
		else if (piece->pos[p + j] != '.' && validate == 1)
			map->pos[y + (x * map->size) +
			ft_pos(p, j, map->size)] = piece->pos[p + j];
		if (piece->pos[p + j + 1] == '\0' && validate == 0)
		{
			j = -1;
			validate = 1;
		}
		j++;
	}
	return (1);
}

int		ft_map_resolve(t_map *map, t_piece *piece)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (piece == NULL)
		return (1);
	while ((int)x < map->size - piece->size->height)
	{
		y = 0 + piece->size->left_width;
		while ((int)y < map->size - piece->size->right_width)
		{
			if (ft_set_piece(map, piece, x, y) == 1)
			{
				if (ft_map_resolve(map, piece->next) == 1)
					return (1);
				else
					ft_del_pieces(map, piece, x, y);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	ft_resolve(t_list *list)
{
	size_t	size;
	t_map	*map;

	size = ft_sqrt_higher(4 * list->lenght);
	map = ft_new_map(size);
	while (ft_map_resolve(map, list->first) == 0)
	{
		free(map->pos);
		free(map);
		size++;
		map = ft_new_map(size);
	}
	ft_map_display(map);
	ft_free_list(list);
}
