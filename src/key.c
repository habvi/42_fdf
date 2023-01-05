#include "fdf.h"
#include "hook.h"
#include <stdio.h> // to do: printf -> ft_printf

static bool	is_rolled_key(t_key keycode)
{
	return (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
			keycode == KEY_UP || keycode == KEY_DOWN || \
			keycode == KEY_ONE || keycode == KEY_TWO || \
			keycode == KEY_J || keycode == KEY_K || \
			keycode == KEY_H || keycode == KEY_L);
}

static void	height_up(t_mlx *mlxs)
{
	if (mlxs->height_emphasis < Z_UPPER_BOUNDS)
		mlxs->height_emphasis += 1;
}

static void	height_down(t_mlx *mlxs)
{
	if (mlxs->height_emphasis > Z_LOWER_BOUNDS)
		mlxs->height_emphasis -= 1;
}

static void	move_image(t_key keycode, t_mlx *mlxs)
{
	if (keycode == KEY_LEFT)
		mlxs->delta_x -= SHIFT_WIDTH;
	else if (keycode == KEY_RIGHT)
		mlxs->delta_x += SHIFT_WIDTH;
	else if (keycode == KEY_UP)
		mlxs->delta_y -= SHIFT_WIDTH;
	else if (keycode == KEY_DOWN)
		mlxs->delta_y += SHIFT_WIDTH;
	else if (keycode == KEY_ONE)
		height_up(mlxs);
	else if (keycode == KEY_TWO)
		height_down(mlxs);
	else if (keycode == KEY_J)
		mlxs->rotate_x_angle += ANGLE_ROTATE;
	else if (keycode == KEY_K)
		mlxs->rotate_x_angle -= ANGLE_ROTATE;
	else if (keycode == KEY_H)
		mlxs->rotate_y_angle -= ANGLE_ROTATE;
	else if (keycode == KEY_L)
		mlxs->rotate_y_angle += ANGLE_ROTATE;
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
