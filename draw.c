#include "fdf.h"

void	transform(t_float3 *point, t_data *var)
{	
	var->joku += 0.00006;
	matrix_proj_init(&var->mat_proj);
	matrix_rotx_init(&var->mat_rx, 1.0f * var->joku);
	matrix_rotz_init(&var->mat_rz, 1.0f * var->joku);

 	// multiply_matrix(point, &var->mat_rz);
 	// multiply_matrix(point, &var->mat_rx);
	
 	point->z = point->z + 25.0f;

 	multiply_matrix(point, &var->mat_proj);

	point->x += 1.0f; 
	point->y += 1.0f;
	point->x *= 0.5f * WIDTH;
 	point->y *= 0.5f * HEIGHT;
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
			transform(&var->transform_points[y][x], var);
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