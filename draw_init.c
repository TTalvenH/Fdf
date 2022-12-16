#include "fdf.h"

// void	zero_map_array (t_float3 *map)
// {
// 	int xi;
// 	int yi;

// 	xi = 0;
// 	yi = 0;
// 	while(map[yi] != NULL)
// 	{
// 		while(map[yi][xi] != NULL)
// 		{
// 			map[yi][xi]->x = 0;
// 			map[yi][xi]->y = 0;
// 			map[yi][xi++]->z = 0;
// 		}
// 		xi = 0;
// 		yi++;
// 	}
// }

void	fill_map(t_float3 **map_points, char *arg)
{
	int		fd;
	char	*map_line;
	char	**line_points;
	int 	xi;
	int		yi;

	xi = 0;
	yi = -1;

	if((fd = open (arg, O_RDONLY)) < 0)
		return ;
	while (yi++ == -1 || map_line != NULL)
	{
		map_line = get_next_line(fd);
		if (map_line)
		{
			line_points = ft_split(map_line, ' ');
			while (line_points[xi] && map_line)
			{
				if (ft_atoi(line_points[xi]) != 0)
					map_points[yi][xi].z = (float)ft_atoi(line_points[xi]);
				map_points[yi][xi].x += (float)xi;
				map_points[yi][xi++].y += (float)yi;
			}
			while (xi > 0)
				free (line_points[xi--]);
			free(line_points);
			free(map_line);
		}
	}
}


void	draw_init(t_map *map_size, char *arg)
{
	t_float3	**map_points;
	int			i;
	// int			j, k;

	// j = 0;
	// k = 0;
	i = 0;
	map_points = malloc(sizeof(t_float3 *) * map_size->rows);
	while (i < map_size->rows)
	{
		map_points[i] = malloc(sizeof(t_float3) * map_size->columns);
		ft_bzero(map_points[i++], (sizeof(t_float3) * (map_size->columns)));
	}
	fill_map(map_points, arg);
	draw(map_points, map_size);
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
}