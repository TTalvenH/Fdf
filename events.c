#include "fdf.h"

int		destroy_data(t_data *var)
{
		mlx_destroy_image(var->mlx, var->img);
		if(var->mlx_win)
			mlx_destroy_window(var->mlx, var->mlx_win);
		free(var->mlx);
		exit(0);
		return (0);
}

int		key_event(int keycode, t_data *var)
{
	key_check1(keycode, var);
	key_check2(keycode, var);
	key_check3(keycode, var);
	return (0);
}

int		mouse_event(int keycode, int x, int y, t_data *var)
{
	if(var->flag == 1)
	{
		if (keycode == MAC_SCROLL_UP)
			var->y_theta += 10;
		if (keycode == MAC_SCROLL_DOWN)
			var->y_theta -= 10;
	}
	else
	{
		if (keycode == MAC_SCROLL_UP)
			var->scale += 1.0;
		if (keycode == MAC_SCROLL_DOWN)
			var->scale -= 1.0;
	}
	return (0);
}

void		init_hooks(t_data *var)
{
	mlx_key_hook(var->mlx_win, &key_event, var);
	mlx_mouse_hook(var->mlx_win, &mouse_event, var);
	mlx_hook(var->mlx_win, ON_DESTROY, 0, destroy_data, var);
	mlx_loop_hook(var->mlx, frame_draw, var);
}