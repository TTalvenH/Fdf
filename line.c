#include "fdf.h"

float	ft_abs(float n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	plot_line_low(t_data *data, t_float2 *p1, t_float2 *p2, int color)
{
	t_line var;

	var.x = (int)p1->x;
	var.y = (int)p1->y;
	var.dx = (int)p2->x - (int)p1->x;
	var.dy = (int)p2->y - (int)p1->y;

	var.sign = 1;
	if (var.dy < 0)
	{
		var.sign = -1;
		var.dy = var.dy * -1;
	}

	var.d = (2 * var.dy) - var.dx;

	while (var.x < p2->x)
	{
		my_mlx_pixel_put(data, var.x++, var.y, color);
		if (var.d > 0)
		{
			var.y = var.y + var.sign;
			var.d = var.d + (2 * (var.dy - var.dx));
		}
		else
			var.d = var.d + 2 * var.dy;
	}
}

void	plot_line_high(t_data *data, t_float2 *p1, t_float2 *p2, int color)
{
	t_line var;

	var.y = (int)p1->y;
	var.x = (int)p1->x;
	var.dx = (int)p2->x - (int)p1->x;
	var.dy = (int)p2->y - (int)p1->y;
	
	var.sign = 1;
	if (var.dx < 0)
	{
		var.sign = -1;
		var.dx = var.dx * -1;
	}

	var.d = (2 * var.dx) - var.dy;

	while (var.y < p2->y)
	{
		my_mlx_pixel_put(data, var.x, var.y++, color);
		if (var.d > 0)
		{
			var.x = var.x + var.sign;
			var.d = var.d + (2 * (var.dx - var.dy));
		}
		else
			var.d = var.d + 2 * var.dx;
	}
}

void	plot_line(t_data *data, t_float2 *p1, t_float2 *p2, int color)
{
	if (ft_abs(p2->y - p1->y) < ft_abs(p2->x - p1->x))
	{
		if (p1->x > p2->x)
			plot_line_low(data, p2, p1, color);
		else
			plot_line_low(data, p1, p2, color);
	}
	else
	{
		if (p1->y > p2->y)
			plot_line_high(data, p2, p1, color);
		else
			plot_line_high(data, p1, p2, color);
	}
}