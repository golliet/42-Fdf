/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chardup_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 07:59:35 by golliet           #+#    #+#             */
/*   Updated: 2018/08/06 14:17:05 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_chardup_spec(const char s1)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	if ((s1 >= 32 && s1 <= 64) || (s1 >= 91 && s1 <= 96) ||
		(s1 >= 123 && s1 <= 126))
	{
		dest[0] = '\\';
		dest[1] = s1;
		dest[2] = '\0';
	}
	else
	{
		dest[0] = s1;
		dest[1] = '\0';
		dest[2] = '\0';
	}
	return (dest);
}
