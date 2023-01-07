#include "fdf.h"
#include "../minilibx/mlx.h"
#include "hook.h"
#include "../libft/include/ft_printf.h"

static bool	is_rolled_mouse(const t_mouse mouse_code)
{
	return (mouse_code == MOUSE_UP || mouse_code == MOUSE_DOWN);
}

static void	move_image(const t_mouse mouse_code, t_mlx *mlxs)
{
	if (mouse_code == MOUSE_UP)
	{
		mlxs->delta_y -= ADJUST_DELTA;
		mlxs->delta_x -= ADJUST_DELTA;
		mlxs->points_distance *= ZOOM_DELTA;
	}
	else if (mouse_code == MOUSE_DOWN)
	{
		mlxs->delta_y += ADJUST_DELTA;
		mlxs->delta_x += ADJUST_DELTA;
		mlxs->points_distance /= ZOOM_DELTA;
	}
}

int	mouse_hook(\
		const t_mouse mouse_code, const int x, const int y, const t_mlx *mlxs)
{
	ft_printf("mousecode : %d, (y, x) = (%d, %d)\n", mouse_code, y, x);
	if (is_rolled_mouse(mouse_code))
	{
		move_image(mouse_code, (t_mlx *)mlxs);
		mlx_destroy_image(mlxs->display->mlx_p, mlxs->img->img);
		set_image(mlxs);
		if (mlxs->img->img == NULL)
			exit_img_p(mlxs);
		draw_image(mlxs);
	}
	return (SUCCESS);
}

int	minimize_window(const t_mlx *mlxs)
{
	draw_image(mlxs);
	return (SUCCESS);
}
