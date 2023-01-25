/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:03:25 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/01/25 18:03:29 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_size(t_data *var, char *arg)
{
	int	fd;

	if ((fd = open (arg, O_RDONLY)) <= 0)
		clean_exit(var);
	while ((var->map_line = get_next_line(fd)))
	{
		if (var->map_size.columns == 0)
		{
			if (!(var->line_points = ft_split(var->map_line, ' ')))
				clean_exit(var);
			while (var->line_points[var->map_size.columns])
				var->map_size.columns++;
			array2_free((void **)var->line_points, var->map_size.columns);
		}
		if (var->map_line != NULL)
			var->map_size.rows++;
		free(var->map_line);
	}
	close(fd);
}
