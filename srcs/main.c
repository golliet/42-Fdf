
#include "fdf.h"

void		go(t_list *list)
{
	(void)list;
	mlx_init();

}

int 		main(int argc, char **argv)
{
	t_list	*list;

	list = NULL;
	if (argc == 2)
	{
		// appel fonction parse
		if (!ft_parse(argv[1], &list))
			ft_putstr("PAS BON \n");
		else
		{
			ft_putstr("BON FICHIER\n");
			// fonction qui transforme un tableau de char * en tableau de t_point
			if (!list)
			{
				ft_putstr_fd("erreur dev null", 2);
				exit(0);
			}
			while (list->prev)
				list = list->prev;
			while (list)
			{
				printf("%d-%d-%d\n", list->x, list->y, list->z);
				list = list->next;
			}
		}
		// fonction dessin 
	}
	else
		ft_putstr("usage : \n"); // display usage
}
