/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:31:18 by tjohanne          #+#    #+#             */
/*   Updated: 2018/01/19 17:31:18 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "fillit.h"

void		ft_map_display(t_map *map)
{
	size_t	i;

	i = 0;
	while ((int)i < map->size * map->size)
	{
		if (i % map->size == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(map->pos[i]);
		i++;
	}
	free(map->pos);
	free(map);
}

t_p_size	*ft_size_pieces(char *tab, size_t i, size_t pos1)
{
	t_p_size	*s_pos;

	s_pos = malloc(sizeof(*s_pos));
	if (s_pos == NULL)
		return (NULL);
	while (tab[i] == '.')
		i++;
	pos1 = i;
	s_pos->left_width = i;
	s_pos->right_width = i;
	s_pos->height = i;
	while (tab[i] != '\0')
	{
		if (tab[i] != '.' && (int)i / 4 > (int)s_pos->height / 4)
			s_pos->height = i;
		if (tab[i] != '.' && (int)i % 4 > s_pos->right_width % 4)
			s_pos->right_width = i;
		if (tab[i] != '.' && (int)i % 4 < s_pos->left_width % 4)
			s_pos->left_width = i;
		i++;
	}
	s_pos->height = s_pos->height / 4 - pos1 / 4;
	s_pos->right_width = s_pos->right_width % 4 - pos1 % 4;
	s_pos->left_width = pos1 % 4 - s_pos->left_width % 4;
	return (s_pos);
}

t_list		*ft_add_piece(char *file, t_list *list)
{
	size_t	i;
	size_t	z;
	char	tab[17];

	z = 0;
	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '.' && z++ < 18)
			tab[z - 1] = file[i];
		if (file[i] == '#' && z++ < 18)
			tab[z - 1] = 'A' + (i + 1) / 21;
		if (z == 16)
		{
			tab[z] = '\0';
			ft_insert_piece(list, tab, ft_size_pieces(tab, 0, 0));
			z = 0;
		}
		i++;
	}
	return (list);
}

int			ft_valid_file(char *file, size_t i, size_t diese, size_t point)
{
	size_t	y;

	y = 0;
	while (file[i++] != '\0')
	{
		if (file[i - 1] == '.')
			point++;
		if (file[i - 1] == '#' && ft_diese_contact(file, i - 1, y, 0) > 0)
			diese++;
		if (file[i - 1] == '#' && ft_diese_contact(file, i - 1, y, 0) > 1)
			diese = diese + 10;
		if (((i - y) % 5 == 0 && file[i - 1] != '\n') ||
			(i % 21 == 0 && file[i - 1] != '\n'))
			return (0);
		if (((i - y) % 20 == 0) &&
			point == 12 && diese % 10 == 4 && diese / 10 > 0)
		{
			point = 0;
			diese = 0;
			y++;
		}
	}
	if (i % 21 == 0 && i < 547 && y == (i / 21))
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	char	file[BUFF_SIZE + 1];
	int		end_of_file;
	int		fd;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("usage : fillit <source_file>\n");
		return (0);
	}
	end_of_file = read(fd, file, BUFF_SIZE);
	if (end_of_file == -1)
		return (0);
	file[end_of_file] = '\0';
	if (!ft_valid_file(file, 0, 0, 0))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_resolve(ft_add_piece(file, ft_new_list()));
	ft_putchar('\n');
	close(fd);
	return (0);
}
