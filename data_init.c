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
	t_fill_var	i;

	i.yi = -1;
	i.fd = open(arg, O_RDONLY);
	if (i.fd <= 0)
		clean_exit(var);
	while (i.yi++ == -1 || var->map_line)
	{
		i.xi = 0;
		var->map_line = get_next_line(i.fd);
		if (var->map_line == NULL)
			break ;
		var->line_points = ft_split(var->map_line, ' ');
		if (!var->line_points)
			clean_exit(var);
		while (var->line_points[i.xi] && var->map_line)
		{
			var->map_p[i.yi][i.xi].y = -(float)ft_atoi(var->line_points[i.xi]);
			set_z_max_min(var, var->map_p[i.yi][i.xi].y);
			var->map_p[i.yi][i.xi].x += (float)i.xi - var->map_size.c / 2;
			var->map_p[i.yi][i.xi++].z += (float)i.yi - var->map_size.r / 2;
		}
		array2_free((void **)var->line_points, i.xi);
		free(var->map_line);
	}
}

void	data_init(t_data *var, char *arg)
{
	var->trans_x = WIDTH / 2;
	var->trans_y = HEIGHT / 2;
	var->scale = 25.0f;
	var->x_theta = 45;
	var->y_theta = 35.264;
	var->map_p = array2_malloc(var->map_size.r, var->map_size.c);
	if (!var->map_p)
		clean_exit(var);
	var->new_p = array2_malloc(var->map_size.r, var->map_size.c);
	if (!var->new_p)
		clean_exit(var);
	fill_map(var, arg);
}
