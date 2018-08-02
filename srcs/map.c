
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
	delta_x = img.size_line / img.nb_elem_line;
	delta_y = img.img_y / img.nb_line;
	// faire le delta z ici
	while (map2[i])
	{
		j = 0;
		while (map2[i][j])
		{
			int x;
			int y;
			int z;

			x = (delta_x/2 * j);
			y = (delta_y/2 * i);
			z = (map2[i][j])->z;
			(map2[i][j])->true_coord.x = cst1 * x - cst2 * y + img.win_x/3;
			(map2[i][j])->true_coord.y = -z*4 + cst1/2 * x + cst2/2 * y + img.win_y/5;
			(map2[i][j])->true_coord.z = (z < 0) ? -z : z;
			j++;
		}
		i++;
	}
}

// algo d'affichage de map

void		put_pixel_1(t_list ***map, t_img *img, int i, int j)
{
	if (map[i][j]->true_coord.z > 0 || map[i][j + 1]->true_coord.z > 0)
		ft_draw_line(img, (t_color){255,map[i][j]->true_coord.z * 50,0}, map[i][j]->true_coord, map[i][j + 1]->true_coord);
	else
		ft_draw_line(img, (t_color){255,255,255}, map[i][j]->true_coord, map[i][j + 1]->true_coord);
}

void		put_pixel_2(t_list ***map, t_img *img, int i, int j)
{
	if (map[i + 1] && map[i + 1][j])
	{
		if (map[i][j]->true_coord.z > 0 || (map[i][j + 1] && map[i][j + 1]->true_coord.z > 0))
			ft_draw_line(img, (t_color){255,0,map[i][j]->true_coord.z * 50}, map[i][j]->true_coord, map[i + 1][j]->true_coord);
		else
			ft_draw_line(img, (t_color){255,255,255}, map[i][j]->true_coord, map[i + 1][j]->true_coord);
	}
}

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
			put_pixel_1(map, img, i, j);
			put_pixel_2(map, img, i, j);
			j++;
		}
		put_pixel_2(map, img, i, j);
		i++;
	}
	j = 0;
	while (map[i][j + 1])
	{
		put_pixel_1(map, img, i, j);
		j++;
	}
}
