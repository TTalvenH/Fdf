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

void set_color(t_float3 *in, t_data *var)
{
	if(in->y < 0)
		in->color = color_interpolate(0x00FFFFFF, 0x00FF0000, in->y / var->z_min);
	else if(in->y > 0)
		in->color = color_interpolate(0x00FFFFFF, 0x000000FF, in->y / var->z_max);
	else 
		in->color = 0x00FFFFFF;
}	
