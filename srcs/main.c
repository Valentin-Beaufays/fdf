#include "libft.h"
#include "fdf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	print_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while(j < map->width)
		{
			printf("%d ", map->map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

void	print_line(t_map *map)
{
	size_t	j;

	j = 0;
	while(j < map->width)
		{
			printf("%d ", map->map[map->height - 1][j]);
			j++;
		}
		printf("\n");
}

size_t get_size(char *line)
{
	size_t	size;

	size = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			while (ft_isdigit(*line))
				line++;
			size++;
		}
		while(*line && !(ft_isdigit(*line)))
			line++;
	}
	return (size);
}

void	fill_line(int *new, char *line)
{
	size_t	i;

	i = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			new[i] = ft_atoi(line);
			i++;
			while(ft_isdigit(*line))
				line++;
		}
		while(*line && !(ft_isdigit(*line)))
			line++;
	}
}

void	add_to_map(t_map *map, int **new_map, int *new)
{
	size_t i;

	i = 0;
	while (i < map->height)
	{
		new_map[i] = map->map[i];
		i++;
	}
	new_map[i] = new;
	if (map->map)
		free(map->map);
	map->map = new_map;
}

int parse_line(t_map *map, char *line)
{
	size_t size;
	int *new;
	int **new_map;

	size = get_size(line);
	if(map->width == 0)
		map->width = size;
	else if (map->width != size)
		return (-1);
	new = malloc(sizeof(*new) * size);
	if (!new)
		return (-1);
	fill_line(new, line);
	new_map = malloc(sizeof(*new_map) * (map->height + 1));
	if (!new_map)
	{
		free(new);
		return (-1);
	}
	add_to_map(map, new_map, new);
	map->height++;
	return (0);
}

int	parser(char *file, t_map *map)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while(get_next_line(fd, &line))
	{
		if ((parse_line(map, line)) == -1)
			return (-1);
		free(line);
	}
	return (0);
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->map = NULL;
}

int	main(int argc, char *argv[])
{
	t_map map;

	init_map(&map);
	if (argc == 2)
	{
		if ((parser(argv[1], &map)) == -1)
			return (-1);
		print_map(&map);
	}
	return (0);
}