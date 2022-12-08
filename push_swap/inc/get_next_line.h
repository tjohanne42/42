/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 06:55:52 by tjohanne          #+#    #+#             */
/*   Updated: 2018/09/04 06:55:52 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFF_SIZE
#  define BUFF_SIZE 9999
# endif
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

int				get_next_line(const int fd, char **line);

#endif
