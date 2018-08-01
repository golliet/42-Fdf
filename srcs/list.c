
#include "fdf.h"

void			ft_add(int x, int y, int z, t_list **list)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		; //malloc failed
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
** j'utilise ma liste chainee pour en faire un tableau ce qui est plus pratique pour fdf
*/

t_list			***ft_fill_tab(t_parse parse, t_list **list)
{
	t_list		***new;
	t_list 		*tmp;
	int			i;

	i = 0;
	tmp = *list;
	if (!(new = (t_list ***)malloc(sizeof(t_list **) * (parse.nb_line + 1))))
		; // malloc failled
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->x == 0)
		{
			if (!(new[tmp->y] = (t_list **)malloc(sizeof(t_list *) * (parse.nb_elem_line + 1))))
				; // malloc failled
		}
		new[tmp->y][tmp->x] = tmp;
		if (!tmp->next)
		{
			new[tmp->y][tmp->x + 1] = NULL;
			new[tmp->y] = NULL;
		}
		else if (tmp->next->x == 0)
			new[tmp->y][tmp->x + 1] = NULL;
		tmp = tmp->next;
	}
	return (new);
}
