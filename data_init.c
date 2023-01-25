/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:04:18 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/01/25 18:04:20 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_z_max_min(t_data *var, float n)
{
	if (n > var->z_max)
		var->z_max = n;
	if (n < var->z_min)
		var->z_min = n;
}

void	fill_map(t_data *var, char *arg)
{
	int	fd;
	int	xi;
	int	yi;

	yi = 0;
	if ((fd = open (arg, O_RDONLY)) <= 0)
		clean_exit(var);
	while ((var->map_line = get_next_line(fd)))
	{
		xi = 0;
		var->line_points = ft_split(var->map_line, ' ');
		if (!var->line_points)
			clean_exit(var);
		while (var->line_points[xi] && var->map_line)
		{
			var->map_points[yi][xi].y = -(float)ft_atoi(var->line_points[xi]);
			set_z_max_min(var, var->map_points[yi][xi].y);
			var->map_points[yi][xi].x += (float)xi - var->map_size.columns / 2;
			var->map_points[yi][xi++].z += (float)yi - var->map_size.rows / 2;
		}
		array2_free((void **)var->line_points, xi);
		free(var->map_line);
		yi++;
	}
}

void	data_init(t_data *var, char *arg)
{
	var->trans_x = WIDTH / 2;
	var->trans_y = HEIGHT / 2;
	var->scale = 25.0f;
	var->x_theta = 45;
	var->y_theta = 35.264;
	var->map_points = array2_malloc(var->map_size.rows, var->map_size.columns);
	if (!var->map_points)
		clean_exit(var);
	var->new_p = array2_malloc(var->map_size.rows, var->map_size.columns);
	if (!var->new_p)
		clean_exit(var);
	fill_map(var, arg);
}
