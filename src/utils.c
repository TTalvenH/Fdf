/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:09:10 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/01/25 18:09:11 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_float3	**array2_malloc(size_t y, size_t x)
{
	t_float3	**array;
	size_t		i;

	i = 0;
	array = malloc(sizeof(t_float3 *) * y);
	if (!array)
		return (array);
	while (i < y)
	{
		array[i] = malloc(sizeof(t_float3) * x);
		if (!array[i])
		{
			array2_free((void **)array, i);
			perror("Error: ");
			exit(1);
		}
		ft_bzero(array[i++], (sizeof(t_float3) * x));
	}
	return (array);
}

void	array2_free(void **array, size_t y)
{
	size_t	i;

	i = 0;
	while (i < y)
		free (array[i++]);
	free (array);
}

void	array2_copy(t_data *var)
{
	size_t	i;

	i = 0;
	while (i < var->map_size.r)
	{
		ft_memcpy(var->new_p[i], var->map_p[i],
			sizeof(t_float3) * var->map_size.c);
		i++;
	}
}

float	percent(float val, float first, float second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

void	rotate(t_data *var)
{
	if (var->y_rotate_flag == 1)
	{
		var->y_theta += 1;
		if (var->y_theta * (M_PI / 180) >= 2 * M_PI)
			var->y_theta = 0;
	}
	if (var->x_rotate_flag == 1)
	{
		var->x_theta += 1;
		if (var->x_theta * (M_PI / 180) >= 2 * M_PI)
			var->x_theta = 0;
	}
	if (var->z_rotate_flag == 1)
	{
		var->z_theta += 1;
		if (var->z_theta * (M_PI / 180) >= 2 * M_PI)
			var->z_theta = 0;
	}
}
