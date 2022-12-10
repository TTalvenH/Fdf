#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "./libft/libft.h"

# define WIDTH 700
# define HEIGHT 700

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

typedef struct	s_box
{
	t_float2	a;
	t_float2	b;
	t_float2	c;
	t_float2	d;
}				t_box;

typedef struct	s_float4
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_float4;

typedef	struct	s_map
{
	size_t	rows;
	size_t	columns;
}				t_map;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		translate_vector(t_float4 *vector, float x, float y, float z);
void		plot_line_low(t_data *data, t_float2 *p1, t_float2 *p2, int color);
void		plot_line_high(t_data *data, t_float2 *p1, t_float2 *p2, int color);
void		plot_line(t_data *data, t_float2 *p1, t_float2 *p2, int color);
t_map		map_size(char *arg);



#endif