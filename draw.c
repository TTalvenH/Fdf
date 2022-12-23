#include "fdf.h"

void	transform(t_float3 *in, t_float3 *out, t_data *var)
{	
	t_float3	rotated;
	t_float3	rotated2;
	t_float3	rotated3;
	t_float3	translated;
	t_float3	scaled;
	t_float3	projected;

	var->joku += 0.0014;
	if (var->joku * (M_PI/180) >= 2 * M_PI)
		var->joku = 0;
	matrix_orth_proj_init(&var->mat_proj);
	matrix_translate_init(&var->mat_trans,500.0f, 500.0f, 0);
	matrix_scale_init(&var->mat_scale, 20.0f);
	matrix_rotate_init(&var->mat_r, var->joku, var->joku,  var->joku);
	matrix_rotx_init(&var->mat_rx, 35 * (M_PI/180));
	matrix_roty_init(&var->mat_ry, 45 * (M_PI/180));
	matrix_rotz_init(&var->mat_rz, 45 * (M_PI/180));
	matrix_rotxy_init(&var->mat_rxy, var->joku * (M_PI/180), var->joku * (M_PI/180));

 	multiply_matrix(in, &scaled, &var->mat_scale);
 	// multiply_matrix(&scaled, &rotated, &var->mat_r);
 	// multiply_matrix(&scaled, &rotated, &var->mat_rz);
 	multiply_matrix(&scaled, &rotated, &var->mat_ry);
 	multiply_matrix(&rotated, &rotated2, &var->mat_rx);
 	// multiply_matrix(&scaled, &rotated2, &var->mat_rxy);
	//  rotated3.x = (rotated2.x - rotated2.y) * cos(0.523599);
	//  rotated3.y = -rotated2.z + (rotated2.x + rotated2.y) * sin(0.523599);
 	// multiply_matrix(&rotated2, &projected, &var->mat_proj);
 	multiply_matrix(&rotated2, out, &var->mat_trans);
}

void	array2_copy(t_data *var)
{
	int i;

	i = 0;
	while (i < var->size->rows)
	{
		ft_memcpy(var->transform_points[i], var->map_points[i], 
							sizeof(t_float3) * var->size->columns);
		i++;
	}
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
			transform(&var->map_points[y][x], &var->transform_points[y][x], var);
			if (y)
				plot_line (var, &var->transform_points[y - 1][x],
						   		&var->transform_points[y][x], var->color);
			if (x)
				plot_line (var, &var->transform_points[y][x - 1],
						   		&var->transform_points[y][x], var->color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, 0, 0);
	return(0);
}

void		init_hooks(t_data *var)
{
	mlx_loop_hook(var->mlx, frame_draw, var);
}

void	init_window(t_data *var)
{
	var->color = 0x0000FF00;
	var->mlx = mlx_init();
	var->mlx_win = mlx_new_window (var->mlx, WIDTH, HEIGHT, "fdf");
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel,
								 &var->line_lenght, &var->endian);
}

void	draw(t_float3 **map_points, t_map *map_size)
{
	t_data	var;

	var.joku = 0;
	var.transform_points = array2_malloc(map_size->rows, map_size->columns);
	var.size = map_size;
	var.map_points = map_points;
	// matrix_proj_init(&var.mat_proj);
	// matrix_rotx_init(&var.mat_rx, 0);
	// matrix_rotz_init(&var.mat_rz, 0);
	init_window(&var);
	// frame_draw(&var);

	init_hooks(&var);
	mlx_loop(var.mlx);
}