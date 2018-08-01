#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

/*
** structure
*/

typedef struct			s_img
{
	unsigned char		*zone_mem;
	int					bit_p; // nombre d'octet par pixel
	int					endian; // endian
	int					size_line; // taille en octet d'une ligne en pixel
	int					img_x;
	int 				img_y;
	int					win_x;
	int					win_y;
	int					nb_elem_line;
	int					nb_line;
}						t_img;

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct 			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct			s_list
{
	int					x;
	int					y;
	int					z;
	t_point				true_coord;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;

typedef struct			s_parse
{
	int					nb_elem_line;
	int					nb_line;
}						t_parse;

/*
** Parsing
*/

int				ft_parse(char *str, t_list **list, t_parse *parse);

/*
** List
*/

void			ft_add(int x, int y, int z, t_list **list);
t_list			***ft_fill_tab(t_parse parse, t_list **list);

/*
** Draw
*/

void			ft_draw_line(t_img *img, t_color color, t_point a, t_point b);
void			put_pixel(t_list ***map, t_img *img);


/*
** Map
*/

void			fill_true_coord(t_list ****map, t_img img);

/*
** Calcul
*/

int				triangle(t_point p1, t_point p2);
double			calc_length(int x1, int y1, int x2, int y2);

#endif
