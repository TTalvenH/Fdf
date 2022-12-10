#include "fdf.h"

void draw_circle(t_data *data ,int x, int y, int r, int color)

{
      double i, angle, x1, y1;

      for(i = 0; i < 360; i += 0.1)

      {
            angle = i;

        	x1 = r * cos(angle * M_PI / 180);
            y1 = r * sin(angle * M_PI / 180);
           	my_mlx_pixel_put(data, x + x1, y + y1, color);
      }
}

int main()
{
	t_data	img;
	t_var	var;
	t_box box ={
				{500.0, 500.0},
				{550.0, 500.0},
				{550.0, 550.0},
				{500.0, 550.0}
				};
	var.color = 0x00FF0000;
	var.mlx = mlx_init();
	if (!var.mlx)
		return (1);
	var.mlx_win = mlx_new_window(var.mlx, 1000, 1000, "test");
	img.img = mlx_new_image(var.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
								 &img.line_lenght, &img.endian);

	// my_mlx_pixel_put(&img, 150, 150, var.color);
	plot_line(&img, &box.a, &box.b, var.color);
	plot_line(&img, &box.b, &box.c, var.color);
	plot_line(&img, &box.c, &box.d, var.color);
	plot_line(&img, &box.d, &box.a, var.color);
	mlx_put_image_to_window(var.mlx, var.mlx_win, img.img, 0, 0);
	mlx_loop(var.mlx);
}