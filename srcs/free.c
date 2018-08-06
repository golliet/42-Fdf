/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:49:37 by golliet           #+#    #+#             */
/*   Updated: 2018/08/06 14:01:17 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_list(t_list **list)
{
	t_list *tmp;

	while ((*list) && (*list)->prev)
		(*list) = (*list)->prev;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}

void		freetab(t_list ***list)
{
	int i;
	int j;

	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			free(list[i][j]);
			j++;
		}
		free(list[i]);
		i++;
	}
	free(list);
}
