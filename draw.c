#include "fdf.h"


void	init_matrices(t_data *var)
{
	matrix_orth_proj_init(&var->mat_proj);
	matrix_proj_init(&var->mat_proj2);
	matrix_translate_init(&var->mat_trans,var->trans_x, var->trans_y, 0);
	matrix_scale_init(&var->mat_scale, var->scale);
	matrix_rotx_init(&var->mat_rx, 45 * (M_PI/180));
	matrix_roty_init(&var->mat_ry, var->theta * (M_PI/180));
	matrix_rotz_init(&var->mat_rz, 0 * (M_PI/180));
}

void	transform(t_float3 *in, t_float3 *out, t_data *var)
{	
	t_float3	rotated;
	t_float3	rotated2;
	t_float3	rotated3;
	t_float3	translated;
	t_float3	scaled;
	t_float3	projected;
	t_float3	projected2;

	init_matrices(var);
	if(var->altitude != 0 && in->y != 0)
	{
		in->y += var->altitude;
		if(in->y < var->z_min)
			var->z_min = in->y;
		if(in->y > var->z_max)
			var->z_max = in->y;
	}
	set_color(in, var);
 	multiply_matrix(in, &scaled, &var->mat_scale);
 	multiply_matrix(&scaled, &rotated, &var->mat_ry);
 	multiply_matrix(&rotated, &rotated2, &var->mat_rz);
 	multiply_matrix(&rotated2, &rotated3, &var->mat_rx);
 	multiply_matrix(&rotated3, &projected, &var->mat_proj); 
 	// multiply_matrix(&projected, out, &var->mat_proj2); 
 	multiply_matrix(&projected, out, &var->mat_trans);
}

int		destroy_data(t_data *var)
{
		mlx_destroy_image(var->mlx, var->img);
		if(var->mlx_win)
			mlx_destroy_window(var->mlx, var->mlx_win);
		free(var->mlx);
		exit(0);
		return (0);
}

int		key_event(int keycode, t_data *var)
{
	if (keycode == 53)
			destroy_data(var);
	if (keycode == 123)
		var->trans_x -= 30;
	if (keycode == 124)
		var->trans_x += 30;
	if (keycode == 125)
		var->trans_y += 30;
	if (keycode == 126)
		var->trans_y -= 30;
	if (keycode == 24)
		var->trans_y += 30;
	if (keycode == 27)
		var->trans_y -= 30;
	if (keycode == 69)
		var->altitude -= 1; 
	if (keycode == 78)
		var->altitude += 1; 
	if (keycode == 12)
	{
		if(!var->flag)
			var->flag = 1;
		else
			var->flag = 0;

	}
	if (keycode == 15)
	{
		var->trans_x = WIDTH / 2;
		var->trans_y = HEIGHT / 2;
		var->scale = 2;
		var->theta = 35.264;
		var->flag = 0;
		var->altitude = 0;
	}
	return (0);
}

int		mouse_event(int keycode, int x, int y, t_data *var)
{
	if(var->flag == 1)
	{
		if (keycode == 4)
			var->theta += 10;
		if (keycode == 5)
			var->theta -= 10;
	}
	else
	{
		if (keycode == 4)
			var->scale += 0.05;
		if (keycode == 5)
			var->scale -= 0.05;
	}
	return (0);
}

void	array2_copy(t_data *var)
{
	int i;

	i = 0;
	while (i < var->size->rows)
	{
		ft_memcpy(var->new_p[i], var->map_points[i], 
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
			transform(&var->new_p[y][x], &var->new_p[y][x], var);
			if (y)
				plot_line (var, &var->new_p[y - 1][x], &var->new_p[y][x]);
			if (x)
				plot_line (var, &var->new_p[y][x - 1], &var->new_p[y][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, 0, 0);
	return(0);
}

void		init_hooks(t_data *var)
{
	mlx_key_hook(var->mlx_win, &key_event, var);
	mlx_mouse_hook(var->mlx_win, &mouse_event, var);
	mlx_hook(var->mlx_win, ON_DESTROY, 0, destroy_data, var);
	mlx_loop_hook(var->mlx, frame_draw, var);
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