#include "parser.h"
#include "error.h"
#include "struct.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>



static t_point **create_map(size_t width, size_t height)
{
	t_point **map;
	size_t	i;

	i = 0;
	map = malloc(sizeof(*map) * height);
	if (!map)
		return (NULL);
	while (i < height)
	{
		map[i] = malloc(sizeof(**map) * width);
		if (!map[i])
		{
			free_map(map, i + 1);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static void	fill_map(t_map *map, t_point **new)
{
	size_t	x;
	size_t	y;
	double	center_x;
	double	center_y;

	center_x = (double)(map->width - 1) / 2.0;
	center_y = (double)(map->height - 1) / 2.0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			new[y][x].x = (double)x - center_x;
			new[y][x].y = (double)y - center_y;
			new[y][x].z = map->map[y][x].z;
			x++;
		}
		y++;
	}
}

void	adapt_map(t_map *map)
{
	t_point **new_map;

	new_map = create_map(map->width, map->height);
	if (!new_map)
	{
		free_map(map->map, map->height);
		exit_error(strerror(errno));
	}
	fill_map(map, new_map);
	free_map(map->map, map->height);
	map->map = new_map;
}