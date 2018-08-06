/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:50:13 by golliet           #+#    #+#             */
/*   Updated: 2018/08/06 13:47:37 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_true_coord(t_list ****map, t_img img, t_var *var)
{
	int		z;

	var->cst1 = 0.3;
	var->cst2 = 1;
	var->i = 0;
	var->delta_x = img.size_line / img.nb_elem_line;
	var->delta_y = img.img_y / img.nb_line;
	while ((*map)[var->i])
	{
		var->j = 0;
		while ((*map)[var->i][var->j])
		{
			var->x = (var->delta_x / 2 * var->j);
			var->y = (var->delta_y / 2 * var->i);
			z = ((*map)[var->i][var->j])->z;
			((*map)[var->i][var->j])->true_coord.x = var->cst1 * var->x
						- var->cst2 * var->y + img.win_x / 3;
			((*map)[var->i][var->j])->true_coord.y = -z * 4 + var->cst1 / 2
						* var->x + var->cst2 / 2 * var->y + img.win_y / 5;
			((*map)[var->i][var->j])->true_coord.z = (z < 0) ? -z : z;
			var->j++;
		}
		var->i++;
	}
}

void		put_pixel_1(t_list ***map, t_img *img, int i, int j)
{
	if (map[i][j]->true_coord.z > 0 || map[i][j + 1]->true_coord.z > 0)
		ft_draw_line(img, (t_color){255, map[i][j]->true_coord.z * 50, 0},
		map[i][j]->true_coord, map[i][j + 1]->true_coord);
	else
		ft_draw_line(img, (t_color){255, 255, 255},
		map[i][j]->true_coord, map[i][j + 1]->true_coord);
}

void		put_pixel_2(t_list ***map, t_img *img, int i, int j)
{
	if (map[i + 1] && map[i + 1][j])
	{
		if (map[i][j]->true_coord.z > 0 || (map[i][j + 1]
			&& map[i][j + 1]->true_coord.z > 0))
			ft_draw_line(img, (t_color){255, 0, map[i][j]->true_coord.z * 50},
			map[i][j]->true_coord, map[i + 1][j]->true_coord);
		else
			ft_draw_line(img, (t_color){255, 255, 255},
			map[i][j]->true_coord, map[i + 1][j]->true_coord);
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
