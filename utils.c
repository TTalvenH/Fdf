#include "fdf.h"

t_float3	**array2_malloc(size_t y, size_t x)
{
	t_float3 **array;
	int i;

	i = 0;
	array = malloc(sizeof(t_float3 *) * y);
	while (i < y)
	{
		array[i] = malloc(sizeof(t_float3) * x);
		ft_bzero(array[i++], (sizeof(t_float3) * x));
	}
	return (array);
}

void	array2_free(void **array, size_t y)
{
	int i;

	i = 0;
	while (i < y)
		free (array[i++]);
	free (array);
}

void	array2_copy(t_data *var)
{
	int i;

	i = 0;
	while (i < var->size->rows)
	{
		ft_memcpy(var->new_p[i], var->map_points[i], 
					sizeof(t_float3) * var->size->columns);
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
	if(var->y_rotate_flag == 1)
	{
		var->y_theta += 1;
		if (var->y_theta * (M_PI/180) >= 2 * M_PI)
			var->y_theta = 0;
	}
	if(var->x_rotate_flag == 1)
	{
		var->x_theta += 1;
		if (var->x_theta * (M_PI/180) >= 2 * M_PI)
			var->x_theta = 0;
	}
	if(var->z_rotate_flag == 1)
	{
		var->z_theta += 1;
		if (var->z_theta * (M_PI/180) >= 2 * M_PI)
			var->z_theta = 0;
	}
}