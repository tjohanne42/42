/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 23:07:15 by tjohanne          #+#    #+#             */
/*   Updated: 2018/09/06 23:07:15 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef OPEN_MAX
# define OPEN_MAX 1200
#endif

static size_t		check_buff(const int fd, char **buff)
{
	char	*temp;
	char	add_to_buff[BUFF_SIZE + 1];
	int		i;

	i = 0;
	if (!(buff[fd]) && !(buff[fd] = ft_strnew(0)))
		return (0);
	while ((i = read(fd, add_to_buff, BUFF_SIZE)) > 0)
	{
		add_to_buff[i] = '\0';
		temp = buff[fd];
		if (!(buff[fd] = ft_strjoin(temp, add_to_buff)))
			return (0);
		free(temp);
		if (ft_strchr(buff[fd], '\n') != NULL)
			return (1);
	}
	if (i < 0)
		return (0);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*buff[OPEN_MAX];
	size_t			i;

	i = 0;
	if (line == NULL || BUFF_SIZE < 1 || fd < 0 || fd > OPEN_MAX - 1)
		return (-1);
	if (!(check_buff(fd, buff)))
		return (-1);
	while (buff[fd][i] != '\n' && buff[fd][i] != '\0')
		i++;
	if (!(*line = ft_strsub(buff[fd], 0, i)))
		return (-1);
	if (ft_strchr(buff[fd], '\n') != NULL)
		ft_strcpy(buff[fd], ft_strchr(buff[fd], '\n') + 1);
	else if (i > 0)
		ft_strcpy(buff[fd], ft_strchr(buff[fd], '\0'));
	else
		return (0);
	return (1);
}
