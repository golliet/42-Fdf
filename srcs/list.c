
#include "fdf.h"

void		ft_add(int x, int y, int z, t_list **list)
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
