#include "struct.h"
#include "fdf.h"
#include "mlx.h"
#include "parser.h"
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

int	init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (-1);
	mlx->win = mlx_new_window(mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	if (!mlx->win)
		return (-1);
	mlx->img = mlx_new_image(mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!mlx->img)
		return (-1);
	return (0);
}

static int	gameloop(t_map *map)
{
	t_mlx	mlx;

	if (init_mlx(&mlx))
		return (-1);
	mlx_loop(mlx.ptr);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	init_map(&map);
	if (argc == 2)
	{
		if (parser(argv[1], &map) || gameloop(&map))
			return (-1);//TO_DO: free map->map
		print_map(&map);
	}
	return (0);
}
