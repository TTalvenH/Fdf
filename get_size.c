#include "fdf.h"



t_arrsize	get_size(char *arg)
{
	char		*map_line;
	char		**line_points;
	t_arrsize	map;
	int			fd;

	map.rows = 0;
	map.columns = 0;
	if((fd = open (arg, O_RDONLY)) <= 0) 
		return (map);
	while ((map_line = get_next_line(fd)))
	{
		if (map.columns == 0)
		{
			line_points = ft_split(map_line, ' ');
			while (line_points[map.columns])
				map.columns++;
			array2_free((void **)line_points, map.columns);
		}
		if (map_line != NULL)
			map.rows++;
		free(map_line);
	}
	close(fd);
	return (map);
}