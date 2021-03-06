/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:49:16 by golliet           #+#    #+#             */
/*   Updated: 2018/08/06 14:00:26 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_change_color(t_img *img, int x, int y, t_color color)
{
	int nb;

	if (x < 0 || y < 0)
		return ;
	if (x >= img->img_x || y >= img->img_y)
		return ;
	nb = y * img->size_line + (img->bit_p / 8) * x;
	img->zone_mem[nb] = color.red;
	img->zone_mem[nb + 1] = color.green;
	img->zone_mem[nb + 2] = color.blue;
}

void		ft_draw_line_deux(t_img *i, t_color color, t_point p1, t_point p2)
{
	int		y;
	int		fp;

	y = p1.y;
	while (y <= p2.y)
	{
		fp = (p2.y - p1.y);
		if (fp == 0)
			return ;
		ft_change_color(i, p1.x + ((p2.x - p1.x) * (y - p1.y)) / fp, y, color);
		y++;
	}
}

void		ft_draw_line_un(t_img *i, t_color color, t_point p1, t_point p2)
{
	int x;
	int fp;

	x = p1.x;
	while (x <= p2.x)
	{
		fp = (p2.x - p1.x);
		if (fp == 0)
			return ;
		ft_change_color(i, x, p1.y + ((p2.y - p1.y) * (x - p1.x)) / fp, color);
		x++;
	}
}

void		ft_draw_line(t_img *img, t_color color, t_point a, t_point b)
{
	int fp;

	fp = 0;
	if (!triangle(a, b, fp))
	{
		if ((a.x >= b.x && a.y <= b.y) || (a.x >= b.x && a.y >= b.y))
			ft_draw_line_un(img, color, b, a);
		else
			ft_draw_line_un(img, color, a, b);
	}
	else
	{
		ft_draw_line_deux(img, color, b, a);
		ft_draw_line_deux(img, color, a, b);
	}
}
