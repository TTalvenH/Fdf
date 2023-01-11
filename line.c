#include "fdf.h"


void	plot_line_low(t_data *var, t_line *pixel, t_float3 *p1, t_float3 *p2)
{
	pixel->x = (int)p1->x;
	pixel->y = (int)p1->y;
	pixel->dx = (int)p2->x - (int)p1->x;
	pixel->dy = (int)p2->y - (int)p1->y;

	if (pixel->dy < 0)
	{
		pixel->sign = -1;
		pixel->dy = pixel->dy * -1;
	}
	pixel->d = (2 * pixel->dy) - pixel->dx;
	while (pixel->x < p2->x)
	{
		pixel->color = set_color(0, 255, 0, 0);
		if ((pixel->x > 0 && pixel->x < WIDTH) && (pixel->y > 0 && pixel->y < HEIGHT))
			my_mlx_pixel_put(var, pixel->x, pixel->y, pixel->color);
		pixel->x++;
		if (pixel->d > 0)
		{
			pixel->y = pixel->y + pixel->sign;
			pixel->d = pixel->d + (2 * (pixel->dy - pixel->dx));
		}
		else
			pixel->d = pixel->d + 2 * pixel->dy;
	}
}

void	plot_line_high(t_data *var, t_line *pixel, t_float3 *p1, t_float3 *p2)
{
	pixel->x = (int)p1->x;
	pixel->y = (int)p1->y;
	pixel->dx = (int)p2->x - (int)p1->x;
	pixel->dy = (int)p2->y - (int)p1->y;

	if (pixel->dx < 0)
	{
		pixel->sign = -1;
		pixel->dx = pixel->dx * -1;
	}
	pixel->d = (2 * pixel->dx) - pixel->dy;
	while (pixel->y < p2->y)
	{
		pixel->color = set_color(0, 255, 0, 0);
		if ((pixel->x > 0 && pixel->x < WIDTH) && (pixel->y > 0 && pixel->y < HEIGHT))
			my_mlx_pixel_put(var, pixel->x, pixel->y, pixel->color);
		pixel->y++;
		if (pixel->d > 0)
		{
			pixel->x = pixel->x + pixel->sign;
			pixel->d = pixel->d + (2 * (pixel->dx - pixel->dy));
		}
		else
			pixel->d = pixel->d + 2 * pixel->dx;
	}
}

void	plot_line(t_data *var, t_float3 *p1, t_float3 *p2)
{
	t_line pixel;

	pixel.sign = 1;

	if (fabs(p2->y - p1->y) < fabs(p2->x - p1->x))
	{
		if (p1->x > p2->x)
			plot_line_low(var, &pixel, p2, p1);
		else
			plot_line_low(var, &pixel, p1, p2);
	}
	else
	{
		if (p1->y > p2->y)
			plot_line_high(var, &pixel, p2, p1);
		else
			plot_line_high(var, &pixel, p1, p2);
	}
}
