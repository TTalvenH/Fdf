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

float	percent(float val, float first, float second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

void	change_altidude(t_data *var, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < var->size->rows)
	{
		j = 0;
		while(j < var->size->columns)
		{
			if(var->map_points[i][j].y != 0)
				var->map_points[i][j].y += n; 
			j++;
		}
		i++;
	}
}