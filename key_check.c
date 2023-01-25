/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:05:18 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/01/25 18:05:20 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_check1(int keycode, t_data *var)
{
	if (keycode == MAC_ESC)
		destroy_data(var);
	if (keycode == MAC_LEFT)
		var->trans_x -= 30;
	if (keycode == MAC_RIGHT)
		var->trans_x += 30;
	if (keycode == MAC_DOWN)
		var->trans_y += 30;
	if (keycode == MAC_UP)
		var->trans_y -= 30;
	if (keycode == MAC_1)
	{
		if (var->y_rotate_flag == 0)
			var->y_rotate_flag = 1;
		else if (var->y_rotate_flag == 1)
			var->y_rotate_flag = 0;
	}
	if (keycode == MAC_2)
	{
		if (var->x_rotate_flag == 0)
			var->x_rotate_flag = 1;
		else if (var->x_rotate_flag == 1)
			var->x_rotate_flag = 0;
	}
}

void	key_check2(int keycode, t_data *var)
{
	if (keycode == MAC_R)
	{
		var->trans_x = WIDTH / 2;
		var->trans_y = HEIGHT / 2;
		var->scale = 25.0f;
		var->x_theta = 45;
		var->y_theta = 35.264;
		var->z_theta = 0;
		var->flag = 0;
		var->x_rotate_flag = 0;
		var->y_rotate_flag = 0;
		var->z_rotate_flag = 0;
	}
}

void	key_check3(int keycode, t_data *var)
{
	if (keycode == MAC_Q)
	{
		if (!var->flag)
			var->flag = 1;
		else
			var->flag = 0;
	}
	if (keycode == MAC_3)
	{
		if (!var->z_rotate_flag)
			var->z_rotate_flag = 1;
		else
			var->z_rotate_flag = 0;
	}
}
