
#include "fdf.h"



// fonction qui voit si un fichier est bon ou pas

static int		ft_lin_is_good(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != ' '))
			return (0);
		i++;
	}
	return (1);
}

static int		ft_open(char *str)
{
	int 	fd;
	int 	lines;
	char	*lin;

	lines = 0;
	if (((fd = open(str, O_RDONLY))) == -1)
	{
		ft_putstr_fd("can't open files\n", 2);
		exit(1);
	}
	while (get_next_line(fd, &lin) > 0)
	{
		if (!ft_lin_is_good(lin))
		{
			free(lin);
			close(fd);
			return (0);
		}
		free(lin);
		lines++;
	}
	close(fd);
	return (lines);
}

static char		**ft_fill_map(char *str, int size)
{
	char 	**map;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (!(map = malloc(sizeof(char *) * size + 1)))
		; // faire une fonction malloc_failled
	if (((fd = open(str, O_RDONLY))) == -1)
	{
		ft_putstr_fd("can't open files\n", 2);
		exit(1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		ft_parse(char *str, char ***map)
{
	int len; 
	int size;

	len = ft_strlen(str);
	if (len == 0)
		return (0);
	if ((size = ft_open(str)))
		*map = ft_fill_map(str, size);
	else
		return (0);
	return (1);
}