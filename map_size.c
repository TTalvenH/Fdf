#include "fdf.h"

t_map	map_size(char *arg)
{
	char		*map_line;
	char		**line_points;
	t_map		map = {};
	int			fd;

	map_line = NULL;
	if((fd = open (arg, O_RDONLY)) < 0)
		return (map);
	while (map_line != NULL || map.rows == 0)
	{
		map_line = get_next_line(fd);
		if (map.columns == 0)
		{
			line_points = ft_split(map_line, ' ');
			while (*line_points)
			{
				map.columns++;
				line_points++;
			}
		}
		if (map_line != NULL)
			map.rows++;
	}
	close(fd);
	return (map);
}