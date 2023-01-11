#include "fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_arrsize 	map_size;
	if (argc == 2)
	{
		map_size = get_size(argv[1]);
		if (!map_size.rows && !map_size.columns)
			return (1);
		draw_init(&map_size, argv[1]);
		printf("%lu and %lu\n", map_size.rows, map_size.columns);
	}
	printf("closed\n");
	return (0);
}