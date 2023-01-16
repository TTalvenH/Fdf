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

void	draw_init(t_arrsize *map_size, char *arg)
{
	t_data		var;
	
	var.trans_x = WIDTH / 2;
	var.trans_y = HEIGHT / 2;
	var.scale = 2.0f;
	var.theta = 0;
	var.theta = 35.264;
	var.flag = 0;
	var.map_points = array2_malloc(map_size->rows, map_size->columns);
	var.new_p = array2_malloc(map_size->rows, map_size->columns);
	var.size = map_size;
	var. z_max = 0;
	var. z_min = 0;


	fill_map(&var, arg);
	set_color(&var);

	int			j, k;
	j = 0;
	k = 0;
	while(j < map_size->rows)
	{
		while (k < map_size->columns)
		{
			printf("%.1f,", var.map_points[j][k].x);
			printf("%.1f,", var.map_points[j][k].z);
			printf("%.1f ", var.map_points[j][k++].y);
		}
		printf("\n");
		j++;
		k = 0;
	}
	
	draw(&var);
}