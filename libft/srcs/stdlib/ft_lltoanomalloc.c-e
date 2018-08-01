/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoanomalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:37:55 by golliet          #+#    #+#             */
/*   Updated: 2018/05/16 10:44:14 by golliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizen(long long n)
{
	long long	nb;
	int			count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	count++;
	return (count);
}

void		lltoanomalloc(long long n, char *toadd)
{
	int			i;
	long long	nb;

	i = sizen(n) - 1;
	nb = n;
	if (!toadd)
		return ;
	if (nb < 0)
		nb = -nb;
	while (nb > 9)
	{
		toadd[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	toadd[i] = nb + 48;
	if (n < 0)
	{
		i--;
		toadd[i] = '-';
	}
	toadd ? toadd[sizen(n)] = '\0' : 0;
}
