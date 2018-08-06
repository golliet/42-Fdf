/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces_spec.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 08:47:09 by golliet           #+#    #+#             */
/*   Updated: 2018/08/06 14:21:09 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strdupi_w(char const *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
	{
		if (s[i + 1] && s[i] == '\\' && s[i + 1] == ' ')
			break ;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = s[i];
		i--;
	}
	return (str);
}

static int	ft_len_words(char const *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != ' ' && s[i] != '\t') || ((s[i] != ' '
		&& s[i] != '\t') && s[i - 1] != '\\'
		&& (s[i - 1] == ' ' || s[i - 1] == '\t')))
			len++;
		i++;
	}
	return (len);
}

char		**ft_split_whitespaces_spec(char const *s)
{
	int		i;
	char	**str;
	int		j;

	str = NULL;
	if (!(s))
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_len_words(s) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != ' ' && s[i] != '\t')
		|| ((s[i] != ' ' && s[i] != '\t')
		&& s[i - 1] == '\\' && (s[i - 1] == ' ' || s[i - 1] == '\t')))
		{
			if (!(str[j] = ft_strdupi_w((s + i))))
				return (NULL);
			j++;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}
