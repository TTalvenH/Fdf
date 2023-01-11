#include "fdf.h"

int	set_color1(t_float3 *point)
{
	if(point->color > 0)
		return(0x00FF0000);
	else if(point->color < 0)
		return(0x000000FF);
	else
		return(0x00FFFFFF);
}

int	set_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
