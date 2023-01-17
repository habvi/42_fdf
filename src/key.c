#include "fdf.h"
#include "hook.h"
#include "mlx.h"
#include "ft_printf.h"

static bool	is_rolled_key(const t_key keycode)
{
	const t_key	keycodes[] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN,
							KEY_ONE, KEY_TWO,
							KEY_J, KEY_K, KEY_H, KEY_L,
							KEY_I, KEY_P, 0};
	size_t		i;

	i = 0;
	while (keycodes[i])
	{
		if (keycode == keycodes[i])
			return (true);
		i++;
	}
	return (false);
}

static void	height_up(t_mlx *mlxs)
{
	if (mlxs->height_emphasis < Z_UPPER_BOUNDS)
		mlxs->height_emphasis += Z_EMPHASIS_DELTA;
}

static void	height_down(t_mlx *mlxs)
{
	if (mlxs->height_emphasis > Z_LOWER_BOUNDS)
		mlxs->height_emphasis -= Z_EMPHASIS_DELTA;
}

static void	move_image(const t_key keycode, t_mlx *mlxs)
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
	else if (keycode == KEY_I)
		mlxs->is_iso = true;
	else if (keycode == KEY_P)
		mlxs->is_iso = false;
}

int	key_hook(const t_key keycode, const t_mlx *mlxs)
{
	ft_printf("keycode : %d\n", keycode);
	if (keycode == KEY_ESC)
		close_window(mlxs);
	else if (is_rolled_key(keycode))
	{
		move_image(keycode, (t_mlx *)mlxs);
		mlx_destroy_image(mlxs->display->mlx_p, mlxs->img->img);
		set_image(mlxs);
		if (mlxs->img->img == NULL)
			exit_img_p(mlxs);
		draw_image(mlxs);
	}
	return (SUCCESS);
}
