#include "fdf.h"
#include <stdio.h>
int main(int argc, char **argv)
{
	t_map	map;
	if (argc == 2)
	{
		map = map_size(argv[1]);
		if (!map.rows && !map.columns)
			return (1);
		printf("%lu and %lu\n", map.rows, map.columns);
	}
	return (0);
}


// int main(int argc, char **argv)
// {
// 	t_data	img;
// 	t_var	var;

// 	var.color = 0x00FF0000;
// 	var.mlx = mlx_init();
// 	if (!var.mlx)
// 		return (1);
// 	var.mlx_win = mlx_new_window(var.mlx, 700, 700, "test");
// 	img.img = mlx_new_image(var.mlx, 700, 700);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
// 								 &img.line_lenght, &img.endian);

// 	// my_mlx_pixel_put(&img, 150, 150, var.color);
// 	mlx_put_image_to_window(var.mlx, var.mlx_win, img.img, 0, 0);
// 	mlx_loop(var.mlx);
// }