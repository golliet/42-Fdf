
#include "fdf.h"

int main(int argc, char **argv)
{
	char **map;

	map = NULL;
	if (argc == 2)
	{
		// appel fonction parse
		if (!ft_parse(argv[1], &map))
			ft_putstr("PAS BON \n");
		else
		{
			ft_putstr("BON FICHIER\n");
			// fonction qui transforme un tableau de char * en tableau de t_point
			int i = 0;
			while (map[i])
			{
				printf("%s\n", map[i]);
				i++;
			}
		}
		// fonction dessin 
	}
	else
		ft_putstr("usage : \n"); // display usage
}