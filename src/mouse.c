#include "fdf.h"
#include "mlx.h"
#include "hook.h"
#include "ft_printf.h"

static bool	is_rolled_mouse(const t_mouse mouse_code)
{
	static const t_mouse	mouse_codes[] = {MOUSE_UP, MOUSE_DOWN};
	static const size_t		len = sizeof(mouse_codes) / sizeof(mouse_codes[0]);
	size_t					i;

	i = 0;
	while (i < len)
	{
		if (mouse_code == mouse_codes[i])
			return (true);
		i++;
	}
	return (false);
}

static void	move_image(const t_mouse mouse_code, t_mlx *mlxs)
{
	if (mouse_code == MOUSE_UP)
	{
		mlxs->delta_y -= ADJUST_DELTA;
		mlxs->delta_x -= ADJUST_DELTA;
		mlxs->points_distance *= ZOOM_DELTA;
		mlxs->height_emphasis *= ZOOM_DELTA;
	}
	else if (mouse_code == MOUSE_DOWN)
	{
		mlxs->delta_y += ADJUST_DELTA;
		mlxs->delta_x += ADJUST_DELTA;
		mlxs->points_distance /= ZOOM_DELTA;
		mlxs->height_emphasis /= ZOOM_DELTA;
	}
}

int	mouse_hook(\
		const t_mouse mouse_code, const int x, const int y, t_mlx *mlxs)
{
	ft_printf("mousecode : %d, (y, x) = (%d, %d)\n", mouse_code, y, x);
	if (is_rolled_mouse(mouse_code))
	{
		move_image(mouse_code, mlxs);
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
