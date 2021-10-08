#ifndef STRUCT_H
# define STRUCT_H

# include <stddef.h>

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct s_map
{
	size_t	height;
	size_t	width;
	t_point	**map;
}				t_map;

#endif