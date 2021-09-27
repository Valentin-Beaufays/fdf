#include "struct.h"
#include <stdio.h>

void	print_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			printf("%d ", map->map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->map = NULL;
}

int	main(int argc, char *argv[])
{
	t_map	map;

	init_map(&map);
	if (argc == 2)
	{
		if ((parser(argv[1], &map)) == -1)
			return (-1);
		print_map(&map);
	}
	return (0);
}
