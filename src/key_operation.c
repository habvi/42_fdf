#include "fdf.h"
#include "hook.h"

void	move_in_4_directions(t_mlx *mlxs, const t_key keycode)
{
	if (keycode == KEY_LEFT)
		mlxs->delta_x -= SHIFT_WIDTH;
	else if (keycode == KEY_RIGHT)
		mlxs->delta_x += SHIFT_WIDTH;
	else if (keycode == KEY_UP)
		mlxs->delta_y -= SHIFT_WIDTH;
	else if (keycode == KEY_DOWN)
		mlxs->delta_y += SHIFT_WIDTH;
}

void	emphasize_height(t_mlx *mlxs, const t_key keycode)
{
	if (keycode == KEY_ONE)
	{
		if (mlxs->height_emphasis < Z_UPPER_BOUNDS)
			mlxs->height_emphasis += Z_EMPHASIS_DELTA;
	}
	else if (keycode == KEY_TWO)
	{
		if (mlxs->height_emphasis > Z_LOWER_BOUNDS)
			mlxs->height_emphasis -= Z_EMPHASIS_DELTA;
	}
}

void	rotate_in_3_directions(t_mlx *mlxs, const t_key keycode)
{
	if (keycode == KEY_J)
		mlxs->rotate_x_angle += ANGLE_ROTATE;
	else if (keycode == KEY_K)
		mlxs->rotate_x_angle -= ANGLE_ROTATE;
	else if (keycode == KEY_H)
		mlxs->rotate_y_angle -= ANGLE_ROTATE;
	else if (keycode == KEY_L)
		mlxs->rotate_y_angle += ANGLE_ROTATE;
	else if (keycode == KEY_N)
		mlxs->rotate_z_angle += ANGLE_ROTATE;
	else if (keycode == KEY_M)
		mlxs->rotate_z_angle -= ANGLE_ROTATE;
}

void	switch_iso(t_mlx *mlxs, const t_key keycode)
{
	if (keycode == KEY_I)
		mlxs->is_iso = true;
	else if (keycode == KEY_P)
		mlxs->is_iso = false;
}
