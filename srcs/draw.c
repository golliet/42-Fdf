
#include "fdf.h"

void ft_change_color(t_img *img, int x, int y, t_color color)
{
	img->zone_mem[y * img->size_line + (img->bit_p/8) * x] = color.red;
	img->zone_mem[y * img->size_line + (img->bit_p/8) * x + 1] = color.green;
	img->zone_mem[y * img->size_line + (img->bit_p/8) * x + 2] = color.blue;
}

static void		ft_draw_line_deux(t_img *img, t_color color, t_point p1, t_point p2)
{
	int y;

	y = p1.y;
	while (y <= p2.y)
	{
		ft_change_color(img, p1.x + ((p2.x - p1.x) * (y - p1.y)) / (p2.y - p1.y), y, color);
		y++;
	}
}

static void		ft_draw_line_un(t_img *img, t_color color, t_point p1, t_point p2)
{
	int x;

	x = p1.x;
	while (x <= p2.x)
	{
		ft_change_color(img, x, p1.y + ((p2.y - p1.y) * (x - p1.x)) / (p2.x - p1.x), color);
		x++;
	}
}

void	ft_draw_line(t_img *img, t_color color, t_point a, t_point b)
{
	if (!triangle(a, b))
	{
		if ((a.x >= b.x && a.y <= b.y) || (a.x >= b.x && a.y >= b.y))
			ft_draw_line_un(img, color, b, a);
		else
			ft_draw_line_un(img, color, a, b);
	}
	else
	{
		if ((a.x >= b.x && a.y <= b.y) || (a.x >= b.x && a.y >= b.y))
			ft_draw_line_deux(img, color, a, b);
		else
			ft_draw_line_deux(img, color, b, a);
	}
}