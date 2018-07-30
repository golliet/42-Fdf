#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

/*
** structure
*/

typedef struct 			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

/*
** Parsing
*/

int			ft_parse(char *str, char ***map);



#endif