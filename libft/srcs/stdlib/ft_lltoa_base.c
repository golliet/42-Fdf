/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:10:00 by golliet           #+#    #+#             */
/*   Updated: 2018/08/06 14:13:27 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isllnegative(long long *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

char			*ft_lltoa_base(long long n, int base)
{
	long long	tmpn;
	long long	len;
	int			negative;
	char		*str;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775807"));
	tmpn = n;
	len = 2;
	negative = ft_isllnegative(&n);
	while (tmpn /= base)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % base + ((n % base > 9) ? ('A' - 10) : ('0'));
		n = n / base;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
