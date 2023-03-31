/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:03:04 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/01/25 18:03:07 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	clean_exit(t_data *var)
{
	if (var->map_line != NULL)
		free(var->map_line);
	if (var->map_p != NULL)
		array2_free((void **)var->map_p, var->map_size.r);
	if (var->new_p != NULL)
		array2_free((void **)var->new_p, var->map_size.r);
	if (var->img != NULL)
		mlx_destroy_image(var->mlx, var->img);
	if (var->mlx_win != NULL)
		mlx_destroy_window(var->mlx, var->mlx_win);
	perror("Error: ");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data		var;

	ft_bzero(&var, sizeof(t_data));
	if (argc == 2)
	{
		get_size(&var, argv[1]);
		if (!var.map_size.r && !var.map_size.c)
			clean_exit(&var);
		data_init(&var, argv[1]);
		draw(&var);
		printf("%lu and %lu\n", var.map_size.r, var.map_size.c);
	}
	printf("closed\n");
	return (0);
}
