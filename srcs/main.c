/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:15:08 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/10/08 12:15:11 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "fdf.h"
#include "mlx.h"
#include "error.h"
#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

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
			printf("%d ", (int)map->map[i][j].z / 10);
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
	map->min.x = 0;
	map->min.y = 0;
	map->min.z = 0;
	map->max.x = 0;
	map->max.y = 0;
	map->max.z = 0;
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
		if (parser(argv[1], &map))
		{
			free_map(map.map, map.height);
			exit_error(strerror(errno));
		}
		print_map(&map);
	}
	return (0);
}
