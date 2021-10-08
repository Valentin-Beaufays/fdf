#include "struct.h"
#include <stddef.h>
#include <stdlib.h>

void free_map(t_point **map, size_t height)
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