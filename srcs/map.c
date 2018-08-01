
# include "fdf.h"

// remplir les vraie coordonnee

void		fill_true_coord(t_list ****map, t_img img)
{
	int 	delta_x;
	int		delta_y;
	int		i;
	int		j;
	t_list 	***map2;

	double cst1;
	double cst2;

	cst1 = 0.3;
	cst2 = 1;

	map2 = *map;
	i = 0;
	printf("img x : %d elem line %d\n", img.img_x, img.nb_elem_line);
	delta_x = img.size_line / img.nb_elem_line;
	delta_y = img.img_y / img.nb_line;
	// faire le delta z ici
	printf("x: %d y: %d\n", delta_x, delta_y);
	while (map2[i])
	{
		j = 0;
		while (map2[i][j])
		{
			//printf("x:%d y:%d\n", (map2[i][j])->x, (map2[i][j])->y);
			int x;
			int y;
			int z;

			x = (delta_x/2 * j);
			y = (delta_y/2 * i);
			z = (map2[i][j])->z;
			(map2[i][j])->true_coord.x = cst1 * x - cst2 * y + 200;
			(map2[i][j])->true_coord.y = -z + cst1/2 * x + cst2/2 * y + 200;
			(map2[i][j])->true_coord.z = z;
			j++;
		}
		i++;
	}
	//*map = map2;
}

// algo d'affichage de map

void		put_pixel(t_list ***map, t_img *img)
{
	int		i;
	int		j;

	i = 0;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j + 1])
		{
			//printf("%d %d\n", i, j);
			// si droite existe alors draw de ce point a celui de droite
			//	printf("la\n");
				if (map[i][j]->true_coord.z > 0)
					ft_draw_line(img, (t_color){255,map[i][j]->true_coord.z * 50,0}, map[i][j]->true_coord, map[i][j + 1]->true_coord);
				else
					ft_draw_line(img, (t_color){255,255,255}, map[i][j]->true_coord, map[i][j + 1]->true_coord);
			// si bas existe alors draw de ce point a celui de bas
			if (map[i + 1] && map[i + 1][j])
			{
				if (map[i][j]->true_coord.z > 0)
				{
					ft_draw_line(img, (t_color){255,0,0}, map[i][j]->true_coord, map[i + 1][j]->true_coord);
				}
				else
				{
					ft_draw_line(img, (t_color){255,255,255}, map[i][j]->true_coord, map[i + 1][j]->true_coord);
				}
			}
			j++;
		}
		i++;
		//printf("ici ?\n");
	}
}