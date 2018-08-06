/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: golliet <golliet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:02:42 by golliet           #+#    #+#             */
/*   Updated: 2018/08/06 14:03:34 by golliet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define ESC 53

typedef struct			s_img
{
	unsigned char		*zone_mem;
	int					bit_p;
	int					endian;
	int					size_line;
	int					img_x;
	int					img_y;
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

typedef struct			s_point
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

typedef struct			s_var
{
	int					delta_x;
	int					delta_y;
	int					i;
	int					j;
	double				cst1;
	double				cst2;
	int					x;
	int					y;
	int					z;
}						t_var;

/*
** Parsing
*/

int						ft_parse(char *str, t_list **list, t_parse *parse);
int						ft_lin_is_good(char *str);

/*
** List
*/

void					ft_add(int x, int y, int z, t_list **list);
t_list					***ft_fill_tab(t_parse parse, t_list **list);

/*
** Draw
*/

void					ft_draw_line(t_img *img, t_color color,
												t_point a, t_point b);
void					put_pixel(t_list ***map, t_img *img);

/*
** Map
*/

void					fill_true_coord(t_list ****map, t_img img, t_var *var);

/*
** Calcul
*/

int						triangle(t_point p1, t_point p2, int fp);
double					calc_length(int x1, int y1, int x2, int y2);

/*
** MISC
*/

void					malloc_failed(void);

/*
** Free
*/

void					free_list(t_list **list);
void					freetab(t_list ***list);

#endif
