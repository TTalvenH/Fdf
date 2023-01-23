#include "fdf.h"

void	set_z_max_min(t_data *var, float n)
{
	if(n > var->z_max)
		var->z_max = n;
	if(n < var->z_min)
		var->z_min = n;
}

void	fill_map(t_data *var, char *arg)
{
	int		fd;
	char	*map_line;
	char	**line_points;
	int 	xi;
	int		yi;

	yi = 0;
	if((fd = open (arg, O_RDONLY)) < 0)
		return ;
	while ((map_line = get_next_line(fd)))
	{
		xi = 0;
		line_points = ft_split(map_line, ' ');
		while (line_points[xi] && map_line)
		{
			var->map_points[yi][xi].y = -(float)ft_atoi(line_points[xi]);
			set_z_max_min(var, var->map_points[yi][xi].y);
			var->map_points[yi][xi].x += (float)xi - var->size->columns / 2;
			var->map_points[yi][xi++].z += (float)yi - var->size->rows / 2;
		}
		array2_free((void**)line_points, xi);
		free(map_line);
		yi++;
	}
}

void	data_init(t_data *var, t_arrsize *map_size, char *arg)
{
	var->trans_x = WIDTH / 2;
	var->trans_y = HEIGHT / 2;
	var->scale = 25.0f;
	var->x_theta = 45;
	var->y_theta = 35.264;
	var->z_theta = 0;
	var->flag = 0;
	var->map_points = array2_malloc(map_size->rows, map_size->columns);
	var->new_p = array2_malloc(map_size->rows, map_size->columns);
	var->size = map_size;
	var->z_max = 0;
	var->z_min = 0;
	var->x_rotate_flag = 0;
	var->y_rotate_flag = 0;
	var->z_rotate_flag = 0;

	zero_matrix4x4(&var->mat_scale);
	zero_matrix4x4(&var->mat_rx);
	zero_matrix4x4(&var->mat_ry);
	zero_matrix4x4(&var->mat_rz);
	zero_matrix4x4(&var->mat_trans);
	zero_matrix4x4(&var->mat_transform);
	fill_map(var, arg);
}