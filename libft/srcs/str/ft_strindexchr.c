/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindexchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:35:41 by bnoufel           #+#    #+#             */
/*   Updated: 2018/02/28 11:20:14 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strindexchr(const char *str, char search)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == search)
			return (i);
		i++;
	}
	return (0);
}
