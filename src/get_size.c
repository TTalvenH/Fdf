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

	fd = open (arg, O_RDONLY);
	if (fd <= 0)
		clean_exit(var);
	while (1)
	{
		var->map_line = get_next_line(fd);
		if (!var->map_line)
			break ;
		if (var->map_size.c == 0)
		{
			var->line_points = ft_split(var->map_line, ' ');
			if (!var->line_points)
				clean_exit(var);
			while (var->line_points[var->map_size.c])
				var->map_size.c++;
			array2_free((void **)var->line_points, var->map_size.c);
		}
		if (var->map_line != NULL)
			var->map_size.r++;
		free(var->map_line);
	}
	close(fd);
}
