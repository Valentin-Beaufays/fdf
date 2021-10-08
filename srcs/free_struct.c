/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:21:48 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/10/08 18:21:50 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stddef.h>
#include <stdlib.h>

void	free_map(t_point **map, size_t height)
{
	if (map)
	{
		while (height > 0)
		{
			free(map[height - 1]);
			height--;
		}
		free(map);
	}
}
