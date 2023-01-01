#include "fdf.h"
#include "hook.h"
#include <stdio.h> // to do: printf -> ft_printf

static bool	is_rolled_key(t_key keycode)
{
	return (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
			keycode == KEY_UP || keycode == KEY_DOWN);
}

static void	move_image(t_key keycode, t_mlx *mlxs)
{
	if (keycode == KEY_LEFT)
		mlxs->delta_x -= KEY_SHIFT;
	else if (keycode == KEY_RIGHT)
		mlxs->delta_x += KEY_SHIFT;
	else if (keycode == KEY_UP)
		mlxs->delta_y -= KEY_SHIFT;
	else if (keycode == KEY_DOWN)
		mlxs->delta_y += KEY_SHIFT;
}

int	key_hook(t_key keycode, t_mlx *mlxs)
{
	printf("keycode : %d\n", keycode);
	if (keycode == KEY_ESC)
		close_window(mlxs);
	else if (is_rolled_key(keycode))
	{
		move_image(keycode, mlxs);
		mlx_destroy_image(mlxs->display->mlx_p, mlxs->img->img);
		set_image(mlxs);
		draw_image(mlxs);
	}
	return (SUCCESS);
}
