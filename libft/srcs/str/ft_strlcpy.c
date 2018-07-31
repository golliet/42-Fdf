/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:19:48 by golliet           #+#    #+#             */
/*   Updated: 2018/02/28 11:20:14 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strlcpy(char *dst, const char *src, int *len)
{
	size_t i;
	size_t k;

	k = 0;
	i = ft_strlen(src);
	while (k < i)
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = '\0';
	(*len) += (int)k;
	return (dst);
}
