/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:04:32 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/01/25 18:04:34 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "./libft/libft.h"
# define WIDTH 1400.0f
# define HEIGHT 1200.0f

# define WHITE 0x007A04EB
# define RED 0x00FF00A0
# define BLUE 0x00120458

enum{
	MAC_ESC = 53,
	MAC_RIGHT = 124,
	MAC_LEFT = 123,
	MAC_UP = 126,
	MAC_DOWN = 125,
	MAC_Q = 12,
	MAC_R = 15,
	MAC_P = 35,
	MAC_1 = 18,
	MAC_2 = 19,
	MAC_3 = 20,
	MAC_SCROLL_UP = 4,
	MAC_SCROLL_DOWN = 5,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_line
{
	int			dx;
	int			dy;
	int			sign;
	int			d;
	int			y;
	int			x;
	int			color;
}				t_line;

typedef struct s_float3
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_float3;

typedef struct s_arrsize
{
	size_t	r;
	size_t	c;
}				t_arrsize;

typedef struct s_mat4x4
{
	float	m[4][4];
}				t_mat4x4;

typedef struct s_fill_var
{
	int	fd;
	int	xi;
	int	yi;
}				t_fill_var;

typedef struct s_color
{
	unsigned char	r1;
	unsigned char	r2;
	unsigned char	g1;
	unsigned char	g2;
	unsigned char	b1;
	unsigned char	b2;
}				t_color;

typedef struct s_data
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	char		*map_line;
	char		**line_points;
	t_float3	**map_p;
	t_float3	**new_p;
	t_arrsize	map_size;
	t_mat4x4	mat_proj;
	t_mat4x4	mat_scale;
	t_mat4x4	mat_rx;
	t_mat4x4	mat_ry;
	t_mat4x4	mat_rz;
	t_mat4x4	mat_trans;
	t_mat4x4	mat_transfrm;
	float		trans_x;
	float		trans_y;
	float		scale;
	float		x_theta;
	float		y_theta;
	float		z_theta;
	int			flag;
	int			z_max;
	int			z_min;
	int			x_rotate_flag;
	int			y_rotate_flag;
	int			z_rotate_flag;
}				t_data;

void		translate_vector(t_float3 *vector, float x, float y, float z);
void		plot_line_low(t_data *var, t_line *p, t_float3 *p1, t_float3 *p2);
void		plot_line_high(t_data *var, t_line *p, t_float3 *p1, t_float3 *p2);
void		plot_line(t_data *var, t_float3 *p1, t_float3 *p2);
void		plot_line1(t_data *var, t_float3 *p1, t_float3 *p2);
void		get_size(t_data *var, char *arg);
void		multiply_with_matrix(t_float3 *in, t_float3 *out, t_mat4x4 *m);
void		zero_matrix4x4(t_mat4x4 *matrix);
t_mat4x4	multiply_matrices(t_mat4x4 *first, t_mat4x4 *second);
void		matrix_orth_proj_init(t_mat4x4 *matrix);
void		matrix_pers_proj_init(t_mat4x4 *matrix);
void		matrix_proj_init(t_mat4x4 *matrix);
void		matrix_rotz_init(t_mat4x4 *matrix, float fTheta);
void		matrix_rotx_init(t_mat4x4 *matrix, float fTheta);
void		matrix_roty_init(t_mat4x4 *matrix, float fTheta);
void		matrix_scale_init(t_mat4x4 *matrix, float x);
void		matrix_translate_init(t_mat4x4 *matrix, float x, float y, float z);
void		data_init(t_data *var, char *arg);
void		fill_map(t_data *var, char *arg);
void		draw(t_data *var);
t_float3	**array2_malloc(size_t y, size_t x);
void		array2_free(void **array, size_t y);
void		array2_copy(t_data *var);
int			color_interpolate(int color1, int color2, float percent);
void		set_color(t_float3 *in, t_data *var);
float		percent(float val, float first, float second);
void		rotate(t_data *var);
void		init_hooks(t_data *var);
int			frame_draw(t_data *var);
void		key_check1(int keycode, t_data *var);
void		key_check2(int keycode, t_data *var);
void		key_check3(int keycode, t_data *var);
int			destroy_data(t_data *var);
void		clean_exit(t_data *var);

#endif
