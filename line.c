/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:03:14 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/01/25 18:03:18 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	plot_line_low(t_data *var, t_line *p, t_float3 *p1, t_float3 *p2)
{
	p->x = (int)p1->x;
	p->y = (int)p1->y;
	p->dx = (int)p2->x - (int)p1->x;
	p->dy = (int)p2->y - (int)p1->y;
	if (p->dy < 0)
	{
		p->sign = -1;
		p->dy = p->dy * -1;
	}
	p->d = (2 * p->dy) - p->dx;
	while (p->x < p2->x)
	{
		p->color = color_interpolate(p1->color, p2->color,
				percent(p->x, p1->x, p2->x));
		if ((p->x > 0 && p->x < WIDTH) && (p->y > 0 && p->y < HEIGHT))
			my_mlx_pixel_put(var, p->x, p->y, p->color);
		p->x++;
		if (p->d > 0)
		{
			p->y = p->y + p->sign;
			p->d = p->d + (2 * (p->dy - p->dx));
		}
		else
			p->d = p->d + 2 * p->dy;
	}
}

void	plot_line_high(t_data *var, t_line *p, t_float3 *p1, t_float3 *p2)
{
	p->x = (int)p1->x;
	p->y = (int)p1->y;
	p->dx = (int)p2->x - (int)p1->x;
	p->dy = (int)p2->y - (int)p1->y;
	if (p->dx < 0)
	{
		p->sign = -1;
		p->dx = p->dx * -1;
	}
	p->d = (2 * p->dx) - p->dy;
	while (p->y < p2->y)
	{
		p->color = color_interpolate(p1->color, p2->color,
				percent(p->y, p1->y, p2->y));
		if ((p->x > 0 && p->x < WIDTH) && (p->y > 0 && p->y < HEIGHT))
			my_mlx_pixel_put(var, p->x, p->y, p->color);
		p->y++;
		if (p->d > 0)
		{
			p->x = p->x + p->sign;
			p->d = p->d + (2 * (p->dx - p->dy));
		}
		else
			p->d = p->d + 2 * p->dx;
	}
}

void	plot_line(t_data *var, t_float3 *p1, t_float3 *p2)
{
	t_line	p;

	p.sign = 1;
	if (fabs(p2->y - p1->y) < fabs(p2->x - p1->x))
	{
		if (p1->x > p2->x)
			plot_line_low(var, &p, p2, p1);
		else
			plot_line_low(var, &p, p1, p2);
	}
	else
	{
		if (p1->y > p2->y)
			plot_line_high(var, &p, p2, p1);
		else
			plot_line_high(var, &p, p1, p2);
	}
}
