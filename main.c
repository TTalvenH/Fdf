#include "fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_map	map_xy;
	if (argc == 2)
	{
		map_xy = map_size(argv[1]);
		if (!map_xy.rows && !map_xy.columns)
			return (1);
		draw_init(&map_xy, argv[1]);
		printf("%lu and %lu\n", map_xy.rows, map_xy.columns);
	}
	return (0);
}

// int main()
// {
// 	t_data	img;
// 	t_var	var;
// 	t_mat4x4 matrix_p;
// 	t_mat4x4 matrix_rotate_z = {};
// 	t_mat4x4 matrix_rotate_x = {};
// 	t_triangle test = {{
// 					  {0.0f, 0.0f, 0.0f},
// 					  {0.0f, 1.0f, 0.0f},
// 					  {1.0f, 1.0f, 0.0f},
// 					  {2.0f, -1.0f, 1.0f}
// 					}};
// 	t_triangle trans = test;
// 	t_triangle out = {};

// 	matrix_proj_init(&matrix_p);



//! 	trans.p[0].z = test.p[0].z + 1.5f;
//! 	multiply_matrix(&trans.p[0], &out.p[0], &matrix_p);
//!		out.p[0].x += 1.0f; out.p[0].y += 1.0f;
//!		out.p[0].x *= 0.5f * WIDTH;
//! 	out.p[0].y *= 0.5f * HEIGHT;
	
// 	trans.p[0].z = test.p[0].z + 1.5f;
// 	trans.p[1].z = test.p[1].z + 1.5f;
// 	trans.p[2].z = test.p[2].z + 1.5f;
// 	trans.p[3].z = test.p[3].z + 1.5f;

// 	multiply_matrix(&trans.p[0], &out.p[0], &matrix_p);
// 	multiply_matrix(&trans.p[1], &out.p[1], &matrix_p);
// 	multiply_matrix(&trans.p[2], &out.p[2], &matrix_p);
// 	multiply_matrix(&trans.p[3], &out.p[3], &matrix_p);

// 	out.p[0].x += 1.0f; out.p[0].y += 1.0f;
// 	out.p[1].x += 1.0f; out.p[1].y += 1.0f;
// 	out.p[2].x += 1.0f; out.p[2].y += 1.0f;
// 	out.p[3].x += 1.0f; out.p[3].y += 1.0f;

// 	out.p[0].x *= 0.5f * WIDTH;
// 	out.p[0].y *= 0.5f * HEIGHT;
// 	out.p[1].x *= 0.5f * WIDTH;
// 	out.p[1].y *= 0.5f * HEIGHT;
// 	out.p[2].x *= 0.5f * WIDTH;
// 	out.p[2].y *= 0.5f * HEIGHT;
// 	out.p[3].x *= 0.5f * WIDTH;
// 	out.p[3].y *= 0.5f * HEIGHT;

// 	var.color = 0x00FF0000;
// 	var.mlx = mlx_init();
// 	if (!var.mlx)
// 		return (1);
// 	var.mlx_win = mlx_new_window(var.mlx, 256, 240, "test");
// 	img.img = mlx_new_image(var.mlx, 256, 240);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
// 								 &img.line_lenght, &img.endian);

// 	// my_mlx_pixel_put(&img, 150, 150, var.color);
// 	plot_line (&img, &out.p[0], &out.p[1], var.color);	
// 	plot_line (&img, &out.p[1], &out.p[2], var.color);	
// 	plot_line (&img, &out.p[2], &out.p[0], var.color);
// 	plot_line (&img, &out.p[0], &out.p[3], var.color);
// 	plot_line (&img, &out.p[1], &out.p[3], var.color);
// 	plot_line (&img, &out.p[2], &out.p[3], var.color);

// 	mlx_put_image_to_window(var.mlx, var.mlx_win, img.img, 0, 0);
// 	mlx_loop(var.mlx);
// }