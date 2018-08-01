
#include "fdf.h"

double			calc_length(int x1, int y1, int x2, int y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int			triangle(t_point p1, t_point p2)
{
	t_point p3;
	double	rad;
	int		fp;

	p3.z = 0;
	if (p1.y > p2.y)
	{
		p3.x = p2.x;
		p3.y = p1.y;
		fp = calc_length(p1.x, p1.y, p2.x, p2.y);
		if (fp == 0)
			return (0);
		rad = acos(calc_length(p1.x, p1.y, p3.x, p3.y) / fp);
		rad = rad * 57.2958;
		return ((rad >= 45 ? 1 : 0));
	}
	else
	{
		p3.x = p1.x;
		p3.y = p2.y;
		fp = calc_length(p1.x, p1.y, p2.x, p2.y);
		if (fp == 0)
			return (0);
		rad = asin(calc_length(p1.x, p1.y, p3.x, p3.y) / fp);
		rad = rad * 57.2958;
		return ((rad >= 45 ? 1 : 0));
	}
}

void		go(t_list ***tab, t_parse parse)
{
	void 	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_img	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 900, 500, "ntm");
	img_ptr = mlx_new_image(mlx_ptr, 900, 500);

	img.win_x = 900;
	img.win_y = 500;
	img.img_x = 900;
	img.img_y = 500;
	printf("x : %d\n", parse.nb_elem_line);
	printf("y : %d\n", parse.nb_line);
	img.nb_elem_line = parse.nb_elem_line;
	img.nb_line = parse.nb_line;
	printf("x : %d\n", img.nb_elem_line);
	printf("y : %d\n", img.nb_line);
	img.zone_mem = (unsigned char *)mlx_get_data_addr(img_ptr, &img.bit_p, &img.size_line, &img.endian);

	fill_true_coord(&tab, img);

	put_pixel(tab, &img);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}

int 		main(int argc, char **argv)
{
	t_list	*list;
	t_parse parse;
	t_list 	***tab;

	list = NULL;
	if (argc == 2)
	{
		parse.nb_elem_line = 0;
		parse.nb_line = 0;
		if (!ft_parse(argv[1], &list, &parse))
			ft_putstr("PAS BON \n");
		else
		{
			ft_putstr("BON FICHIER\n");
			if (!list)
			{
				ft_putstr_fd("erreur dev null", 2);
				exit(0);
			}
			printf("x : %d\n", parse.nb_elem_line);
			printf("y : %d\n", parse.nb_line);
			tab = ft_fill_tab(parse, &list);
			go(tab, parse);
		}
	}
	else
		ft_putstr("usage : \n"); // display usage
}
