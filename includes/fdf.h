#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

/*
** structure
*/

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
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;

/*
** Parsing
*/

int			ft_parse(char *str, t_list **list);

/*
** List
*/

void		ft_add(int x, int y, int z, t_list **list);

#endif
