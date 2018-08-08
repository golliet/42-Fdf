/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:49:59 by golliet           #+#    #+#             */
/*   Updated: 2018/08/07 10:42:50 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		calc_length(int x1, int y1, int x2, int y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int			triangle(t_point p1, t_point p2, int fp)
{
	t_point p3;
	double	rad;

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

int			esc_hook(int keycode, void *param)
{
	if (keycode == ESC)
	{
		freetab(param);
		exit(0);
	}
	return (1);
}

void		go(t_list ***tab, t_parse parse)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_img	img;
	t_var	var;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 900, 500, "fdf");
	img_ptr = mlx_new_image(mlx_ptr, 900, 500);
	img.win_x = 900;
	img.win_y = 500;
	img.img_x = 900;
	img.img_y = 500;
	img.nb_elem_line = parse.nb_elem_line;
	img.nb_line = parse.nb_line;
	img.zone_mem = (unsigned char *)mlx_get_data_addr(img_ptr, &img.bit_p,
					&img.size_line, &img.endian);
	fill_true_coord(&tab, img, &var);
	put_pixel(tab, &img);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_key_hook(win_ptr, esc_hook, tab);
	mlx_loop(mlx_ptr);
}

int			main(int argc, char **argv)
{
	t_list		*list;
	t_parse		parse;
	t_list		***tab;

	list = NULL;
	if (argc == 2)
	{
		parse.nb_elem_line = 0;
		parse.nb_line = 0;
		if (!ft_parse(argv[1], &list, &parse))
			ft_putstr_fd("invalid file\n", 2);
		else
		{
			if (!list)
			{
				ft_putstr_fd("erreur null\n", 2);
				exit(0);
			}
			tab = ft_fill_tab(parse, &list);
			go(tab, parse);
		}
	}
	else
		ft_putstr("usage : ./fdf + [file]\n");
}
