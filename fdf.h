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

# define WIDTH 1900.0f
# define HEIGHT 1300.0f
# define Near 0.1f
# define Far 100.0f
# define Right 10.0f
# define Left -10.0f
# define Top 10.0f
# define Bottom -10.0f

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sign;
	int			d;
	int			y;
	int			x;
	int			color;
}				t_line;

typedef struct	s_float3
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_float3;

typedef	struct	s_arrsize
{
	size_t	rows;
	size_t	columns;
}				t_arrsize;

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
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	t_float3	**map_points;
	t_float3	**new_p;
	t_arrsize 	*size;
	t_mat4x4	mat_proj;
	t_mat4x4	mat_scale;
	t_mat4x4	mat_rx;
	t_mat4x4	mat_ry;
	t_mat4x4	mat_rz;
	t_mat4x4	mat_trans;
	float		trans_x;
	float		trans_y;
	float		scale;
	float		theta;
	int			flag;

}				t_data;

void		my_mlx_pixel_put(t_data *var, int x, int y, int color);
void		translate_vector(t_float3 *vector, float x, float y, float z);
void		plot_line_low(t_data *var, t_line *pixel, t_float3 *p1, t_float3 *p2);
void		plot_line_high(t_data *var, t_line *pixel, t_float3 *p1, t_float3 *p2);
void		plot_line(t_data *var, t_float3 *p1, t_float3 *p2);
void 		plot_line1(t_data *var, t_float3 *p1, t_float3 *p2);
t_arrsize	get_size(char *arg);
void		multiply_matrix(t_float3 *in, t_float3 *out, t_mat4x4 * m);
void		matrix_orth_proj_init(t_mat4x4 *matrix);
void 		matrix_rotz_init(t_mat4x4 *matrix, float fTheta);
void		matrix_rotx_init(t_mat4x4 *matrix, float fTheta);
void		matrix_roty_init(t_mat4x4 *matrix, float fTheta);
void		matrix_scale_init(t_mat4x4 *matrix,float x);
void		matrix_translate_init(t_mat4x4 *matrix, float x, float y, float z);
void		draw_init(t_arrsize *map_size, char *arg);
void		fill_map(t_float3 **map_points, char *arg);
void		draw(t_data *var);
t_float3	**array2_malloc(size_t y, size_t x);
void		array2_free(t_float3 **array, size_t y);
int			set_color(int t, int r, int g, int b);










#endif