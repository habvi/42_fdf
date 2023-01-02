#include "fdf.h"
#include "hook.h"
#include <stdio.h> // to do: printf -> ft_printf

static bool	is_rolled_mouse(t_mouse mouse_code)
{
	return (mouse_code == MOUSE_UP || mouse_code == MOUSE_DOWN);
}

static void	move_image(t_mouse mouse_code, t_mlx *mlxs)
{
	if (mouse_code == MOUSE_UP)
	{
		mlxs->delta_y -= 10;
		mlxs->delta_x -= 10;
		mlxs->points_distance *= 1.25;
	}
	else if (mouse_code == MOUSE_DOWN)
	{
		mlxs->delta_y += 10;
		mlxs->delta_x += 10;
		mlxs->points_distance /= 1.25;
	}
}

int	mouse_hook(t_mouse mouse_code, int x, int y, t_mlx *mlxs)
{
	printf("mousecode : %d, (y, x) = (%d, %d)\n", mouse_code, y, x);
	if (is_rolled_mouse(mouse_code))
	{
		move_image(mouse_code, mlxs);
		mlx_destroy_image(mlxs->display->mlx_p, mlxs->img->img);
		set_image(mlxs);
		draw_image(mlxs);
	}
	return (SUCCESS);
}
