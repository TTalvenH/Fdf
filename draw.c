#include "fdf.h"

void	transform(t_float3 *in, t_float3 *out, t_data *var)
{	
	matrix_translate_init(&var->mat_trans, var->trans_x, var->trans_y, 0);
	matrix_scale_init(&var->mat_scale, var->scale);
	matrix_rotx_init(&var->mat_rx, var->x_theta * (M_PI/180));
	matrix_roty_init(&var->mat_ry, var->y_theta * (M_PI/180));
	matrix_rotz_init(&var->mat_rz, var->z_theta * (M_PI/180));
	zero_matrix4x4(&var->mat_transform);
	var->mat_transform = multiply_matrices(&var->mat_trans, &var->mat_rx);
	var->mat_transform = multiply_matrices(&var->mat_transform, &var->mat_ry);
	var->mat_transform = multiply_matrices(&var->mat_transform, &var->mat_rz);
	var->mat_transform = multiply_matrices(&var->mat_transform, &var->mat_scale);
	set_color(in, var);
	multiply_with_matrix(in, out, &var->mat_transform);
}

int		frame_draw(t_data *var) 
{	
	size_t		y;
	size_t		x;

	y = 0;

	array2_copy(var);
	ft_bzero(var->addr, sizeof(int) * (WIDTH * HEIGHT));
	while (y < var->size->rows)
	{
		x = 0;
		while(x < var->size->columns)
		{	
			transform(&var->map_points[y][x], &var->new_p[y][x], var);
			if (y)
				plot_line (var, &var->new_p[y - 1][x], &var->new_p[y][x]);
			if (x)
				plot_line (var, &var->new_p[y][x - 1], &var->new_p[y][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, 0, 0);
	rotate(var);
	return(0);
}

void	init_window(t_data *var)
{
	var->mlx = mlx_init();
	var->mlx_win = mlx_new_window (var->mlx, WIDTH, HEIGHT, "fdf");
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel,
								 &var->line_lenght, &var->endian);
}

void	draw(t_data *var)
{
	init_window(var);
	init_hooks(var);
	mlx_loop(var->mlx);
}