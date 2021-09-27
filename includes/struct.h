#ifndef STRUCT_H
# define STRUCT_H

# include <stddef.h>

typedef struct s_map
{
	size_t	height;
	size_t	width;
	int		**map;
}				t_map;

#endif