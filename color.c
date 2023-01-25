/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:04:50 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/01/25 18:04:58 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_interpolate(int color1, int color2, float percent)
{
	t_color	colors;

	colors.r1 = (color1 >> 16) & 0xff;
	colors.r2 = (color2 >> 16) & 0xff;
	colors.g1 = (color1 >> 8) & 0xff;
	colors.g2 = (color2 >> 8) & 0xff;
	colors.b1 = color1 & 0xff;
	colors.b2 = color2 & 0xff;
	return ((int)((colors.r2 - colors.r1) * percent + colors.r1) << 16 |
			(int)((colors.g2 - colors.g1) * percent + colors.g1) << 8 |
			(int)((colors.b2 - colors.b1) * percent + colors.b1));
}

void	set_color(t_float3 *in, t_data *var)
{
	if (in->y < 0)
		in->color = color_interpolate(WHITE, RED, in->y / var->z_min);
	else if (in->y > 0)
		in->color = color_interpolate(WHITE, BLUE, in->y / var->z_max);
	else
		in->color = WHITE;
}
