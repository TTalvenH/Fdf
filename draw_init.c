#include "fdf.h"

void	fill_map(t_float3 **map_points, char *arg)
{
	int		fd;
	char	*map_line;
	char	**line_points;
	int 	xi;
	int		yi;

	yi = -1;

	if((fd = open (arg, O_RDONLY)) < 0)
		return ;
	while (yi++ == -1 || map_line != NULL)
	{
		xi = 0;
		map_line = get_next_line(fd);
		if (map_line)
		{
			line_points = ft_split(map_line, ' ');
			while (line_points[xi] && map_line)
			{
				map_points[yi][xi].color = (float)ft_atoi(line_points[xi]);
				map_points[yi][xi].y = -(float)ft_atoi(line_points[xi]);
				map_points[yi][xi].x += (float)xi;
				map_points[yi][xi++].z += (float)yi;
			}
			while (xi >= 0)
				free (line_points[xi--]);
			free(line_points);
			free(map_line);
		}
	}
}


t_float3	**array2_malloc(size_t y, size_t x)
{
	t_float3 **array;
	int i;

	i = 0;
	array = malloc(sizeof(t_float3 *) * y);
	while (i < y)
	{
		array[i] = malloc(sizeof(t_float3) * x);
		ft_bzero(array[i++], (sizeof(t_float3) * x));
	}
	return (array);
}

void	array2_free(t_float3 **array, size_t y)
{
	int i;

	i = 0;
	while (i < y)
		free (array[i++]);
	free (array);
}
void	draw_init(t_arrsize *map_size, char *arg)
{
	t_data		var;
	
	var.trans_x = WIDTH / 2;
	var.trans_y = HEIGHT / 2;
	var.scale = 2.0f;
	var.theta = 35.264;
	var.flag = 0;
	var.map_points = array2_malloc(map_size->rows, map_size->columns);
	var.new_p = array2_malloc(map_size->rows, map_size->columns);
	var.size = map_size;


	fill_map(var.map_points, arg);

	// int			j, k;
	// j = 0;
	// k = 0;
	// while(j < map_size->rows)
	// {
	// 	while (k < map_size->columns)
	// 	{
	// 		printf("%.1f,", map_points[j][k].x);
	// 		printf("%.1f,", map_points[j][k].y);
	// 		printf("%.1f ", map_points[j][k++].z);
	// 	}
	// 	printf("\n");
	// 	j++;
	// 	k = 0;
	// }

	draw(&var);
}