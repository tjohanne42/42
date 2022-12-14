/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:26:08 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/30 15:26:09 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

intmax_t	ft_atoimax(const char *nptr)
{
	size_t 		i;
	intmax_t 	nb;
	intmax_t 	signe;

	signe = 44;
	nb = 0;
	i = 0;
	while ((nptr[i] < 14 && nptr[i] > 8) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		signe = signe - nptr[i];
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	if (signe != 44)
		return (nb * signe);
	return (nb);
}
