#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "./libft/libft.h"
#include <stdio.h> // ! poistaaaaaaa

# define WIDTH 1000.0f
# define HEIGHT 1000.0f
# define fNear 0.1f
# define fFar 10.0f
# define fFov 90.0f
# define fAspectRatio HEIGHT / WIDTH
# define fFovRad 1.0f / tan(fFov * 0.5f / 180.0f * M_PI)
# define Right 10.0f
# define Left 0.0f
# define Top 10.0f
# define Bottom 0.0f

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sign;
	int			d;
	int			y;
	int			x;
}				t_line;

typedef struct	s_float3
{
	float	x;
	float	y;
	float	z;
}				t_float3;

typedef	struct	s_map
{
	size_t	rows;
	size_t	columns;
}				t_map;

typedef struct	s_mat4x4
{
		float	m[4][4];
}				t_mat4x4;

typedef struct 	s_data
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			color;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	t_float3	**map_points;
	t_float3	**transform_points;
	t_map 		*size;
	t_mat4x4	mat_proj;
	t_mat4x4	mat_rx;
	t_mat4x4	mat_rz;
	float		joku;

}				t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		translate_vector(t_float3 *vector, float x, float y, float z);
void		plot_line_low(t_data *data, t_float3 *p1, t_float3 *p2, int color);
void		plot_line_high(t_data *data, t_float3 *p1, t_float3 *p2, int color);
void		plot_line(t_data *data, t_float3 *p1, t_float3 *p2, int color);
t_map		map_size(char *arg);
void		multiply_matrix(t_float3 *in, t_mat4x4 * m);
void		matrix_proj_init(t_mat4x4 *matrix);
void		matrix_orth_proj_init(t_mat4x4 *matrix);
void 		matrix_rotz_init(t_mat4x4 *matrix, float fTheta);
void		matrix_rotx_init(t_mat4x4 *matrix, float fTheta);
void		draw_init(t_map *map_size, char *arg);
void		fill_map(t_float3 **map_points, char *arg);
void		draw(t_float3 **map_points, t_map *map_size);
t_float3	**array2_malloc(size_t y, size_t x);









#endif