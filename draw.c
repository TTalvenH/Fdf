#include "fdf.h"

void	transform(t_float3 *point, t_mat4x4 *matrix, t_mat4x4 *matrix1)
{
 	point->z += 25.5f;
 	multiply_matrix(point, point, matrix1);
 	multiply_matrix(point, point, matrix);
	point->x += 1.0f; point->y += 1.0f;
	point->x *= 0.5f * WIDTH;
 	point->y *= 0.5f * HEIGHT;
}

int		frame_draw(t_data *var) 
{	
	size_t		y;
	size_t		x;

	y = 0;
	ft_bzero(var->addr, WIDTH * HEIGHT);
	while (y < var->size->rows)
	{
		x = 0;
		while(x < var->size->columns)
		{	
			transform(&var->map_points[y][x], &var->m, &var->r);
			if (y)
			{
				plot_line (var, &var->map_points[y - 1][x],
						   			 &var->map_points[y][x], var->color);
			}
			if (x)
			{
				plot_line (var, &var->map_points[y][x - 1],
						   			 &var->map_points[y][x], var->color);
			}
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

	var.size = map_size;
	var.map_points = map_points;
	matrix_proj_init(&var.m);
	matrix_rotz_init(&var.r, 0.80);
	init_window(&var);
	frame_draw(&var);

	// init_hooks(&var);
	mlx_loop(var.mlx);
}