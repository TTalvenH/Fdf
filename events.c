/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:05:06 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/01/25 18:05:08 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_data(t_data *var)
{
	free(var->map_line);
	array2_free((void **)var->map_p, var->map_size.r);
	array2_free((void **)var->new_p, var->map_size.r);
	mlx_destroy_image(var->mlx, var->img);
	mlx_destroy_window(var->mlx, var->mlx_win);
	exit(0);
	return (0);
}

int	key_event(int keycode, t_data *var)
{
	key_check1(keycode, var);
	key_check2(keycode, var);
	key_check3(keycode, var);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_data *var)
{
	if (var->flag == 1)
	{
		if (keycode == MAC_SCROLL_UP)
			var->y_theta += 10;
		if (keycode == MAC_SCROLL_DOWN)
			var->y_theta -= 10;
	}
	else
	{
		if (keycode == MAC_SCROLL_UP)
			var->scale += 1.0;
		if (keycode == MAC_SCROLL_DOWN)
			var->scale -= 1.0;
	}
	return (0);
}

void	init_hooks(t_data *var)
{
	mlx_key_hook(var->mlx_win, &key_event, var);
	mlx_mouse_hook(var->mlx_win, &mouse_event, var);
	mlx_hook(var->mlx_win, ON_DESTROY, 0, destroy_data, var);
	mlx_loop_hook(var->mlx, frame_draw, var);
}
