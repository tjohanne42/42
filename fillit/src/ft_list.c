/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:30:52 by tjohanne          #+#    #+#             */
/*   Updated: 2018/01/19 17:30:54 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	ft_free_list(t_list *list)
{
	t_piece		*temp;

	temp = list->first;
	list->first = temp->next;
	while (temp != NULL)
	{
		free(temp->size);
		free(temp);
		temp = list->first;
		if (temp != NULL)
			list->first = temp->next;
	}
	free(list);
}

t_map	*ft_new_map(size_t size)
{
	t_map	*map;
	size_t	i;

	i = 0;
	map = malloc(sizeof(t_map));
	map->pos = malloc(sizeof(char) * (size * size + 1));
	if (map == NULL || map->pos == NULL)
		return (NULL);
	map->size = size;
	map->pos[size * size] = '\0';
	while (i < size * size)
	{
		map->pos[i] = '.';
		i++;
	}
	return (map);
}

t_list	*ft_new_list(void)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	list->first = NULL;
	list->lenght = 0;
	return (list);
}

int		ft_insert_piece(t_list *list, char *tab, t_p_size *size)
{
	t_piece	*new_piece;
	t_piece	*temp;
	size_t	i;

	i = 0;
	new_piece = (t_piece*)malloc(sizeof(*new_piece));
	if (new_piece == NULL)
		return (0);
	if (list->first == NULL)
		list->first = new_piece;
	else
	{
		temp = list->first;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_piece;
	}
	new_piece->size = size;
	while (i++ < 18)
		new_piece->pos[i - 1] = tab[i - 1];
	new_piece->next = NULL;
	list->lenght++;
	return (1);
}
