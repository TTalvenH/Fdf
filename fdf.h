#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "./libft/libft.h"

# define WIDTH 256.0f
# define HEIGHT 240.0f
# define fNear 0.1f
# define fFar 1000.0f
# define fFov 90.0f
# define fAspectRatio HEIGHT / WIDTH
# define fFovRad 1.0f / tan(fFov * 0.5f / 180.0f * M_PI)

typedef struct 	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
}				t_data;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sign;
	int			d;
	int			y;
	int			x;
}				t_line;

typedef	struct	s_var
{
	void	*mlx;
	void	*mlx_win;
	int		color;
}				t_var;

typedef struct	s_float2
{
	float	x;
	float	y;
}				t_float2;


typedef struct	s_float3
{
	float	x;
	float	y;
	float	z;
}				t_float3;

typedef struct	s_triangle
{
	t_float3	p[4];
}				t_triangle;

typedef struct	s_mat4x4
{
		float	m[4][4];
}				t_mat4x4;

typedef	struct	s_map
{
	size_t	rows;
	size_t	columns;
}				t_map;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		translate_vector(t_float3 *vector, float x, float y, float z);
void		plot_line_low(t_data *data, t_float3 *p1, t_float3 *p2, int color);
void		plot_line_high(t_data *data, t_float3 *p1, t_float3 *p2, int color);
void		plot_line(t_data *data, t_float3 *p1, t_float3 *p2, int color);
t_map		map_size(char *arg);
void		multiply_matrix(t_float3 *in, t_float3 *out, t_mat4x4 * m);
void		matrix_proj_init(t_mat4x4 *matrix);
void 		matrix_rotz_init(t_mat4x4 *matrix, float fTheta);
void		matrix_rotx_init(t_mat4x4 *matrix, float fTheta);
void		draw_init(t_map *map, char *arg);







#endif