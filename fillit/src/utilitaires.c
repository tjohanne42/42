/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaires.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:31:27 by tjohanne          #+#    #+#             */
/*   Updated: 2018/01/19 17:31:28 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		ft_diese_contact(const char *file, size_t i, size_t y, size_t z)
{
	if ((i + 1 - y) % 5 != 1 && file[i - 1] == '#')
		z++;
	if ((i + 1 - y) % 5 != 0 && file[i + 1] == '#')
		z++;
	if ((i + 1) % 21 > 5 && file[i - 5] == '#')
		z++;
	if ((i + 1) % 21 < 16 && file[i + 5] == '#')
		z++;
	return (z);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int		ft_sqrt_higher(int nb)
{
	int		i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}
