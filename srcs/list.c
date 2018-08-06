/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:49:50 by golliet           #+#    #+#             */
/*   Updated: 2018/08/06 13:58:33 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_add(int x, int y, int z, t_list **list)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		malloc_failed();
	new->next = NULL;
	new->x = x;
	new->y = y;
	new->z = z;
	if (!*list)
	{
		new->prev = NULL;
		*list = new;
	}
	else
	{
		while ((*list)->next)
			*list = (*list)->next;
		(*list)->next = new;
		(*list)->next->prev = *list;
		(*list)->next->next = NULL;
	}
}

/*
** double array de pointeur sur structure
** j'utilise ma liste chainee pour en
** faire un tableau ce qui est plus pratique pour fdf
*/

t_list			***ft_fill_tab(t_parse parse, t_list **list)
{
	t_list		***new;
	t_list		*tmp;

	tmp = *list;
	if (!(new = (t_list ***)malloc(sizeof(t_list **) * (parse.nb_line + 5))))
		malloc_failed();
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->x == 0)
			if (tmp->x == 0 && !(new[tmp->y] = (t_list**)malloc(sizeof(t_list*)
							* (parse.nb_elem_line + 1))))
				malloc_failed();
		new[tmp->y][tmp->x] = tmp;
		if (!tmp->next)
		{
			new[tmp->y][tmp->x + 1] = NULL;
			new[tmp->y + 1] = NULL;
		}
		else if (tmp->next->x == 0)
			new[tmp->y][tmp->x + 1] = NULL;
		tmp = tmp->next;
	}
	return (new);
}

int				ft_lin_is_good(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != ' ')
		&& (str[i + 1] && str[i] != '-' && ((str[i] < '0' || str[i] > '9'))))
			return (0);
		i++;
	}
	return (1);
}

void			malloc_failed(void)
{
	ft_putendl("malloc has failed");
	exit(EXIT_FAILURE);
}
