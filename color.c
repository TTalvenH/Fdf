#include "fdf.h"

int	color_interpolate(int color1, int color2, float percent)
{
	unsigned char r1 = (color1 >> 16) & 0xff;
	unsigned char r2 = (color2 >> 16) & 0xff;
	unsigned char g1 = (color1 >> 8) & 0xff;
	unsigned char g2 = (color2 >> 8) & 0xff;
	unsigned char b1 = color1 & 0xff;
	unsigned char b2 = color2 & 0xff;
	
	return ((int)((r2 - r1) * percent + r1) << 16 	|
			(int)((g2 - g1) * percent + g1) << 8 	|
			(int)((b2 - b1) * percent + b1));
}

void set_color(t_data *var)
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
			if(var->map_points[i][j].y < 0)
				var->map_points[i][j].color = color_interpolate(
				0x006F7231, 0x00C8040E,var->map_points[i][j].y / var->z_min);
			else if(var->map_points[i][j].y > 0)
				var->map_points[i][j].color = color_interpolate(
				0x006F7231, 0x003E58B6, var->map_points[i][j].y / var->z_max);
			else var->map_points[i][j].color = 0x006F7231;
			j++;
		}
		i++;
	}
}	
