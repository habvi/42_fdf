#include "fdf.h"
#include "hook.h"
#include <stdio.h> // to do: erase printf

static int	mouse_hook(t_mouse mouse_code, t_mlx *mlxs)
{
	printf("mousecode : %d %d\n", mouse_code, mouse_code == MOUSE_LEFT);
	(void)mlxs;
	// if (mouse_code == MOUSE_LEFT)
	// {
		// printf("%d\n", mlxs->delta_x);
		// mlxs->delta_x += 10;
	// }
	// else if (mouse_code == MOUSE_RIGHT)
	// 	mlxs->delta_x -= 10;
	return (SUCCESS);
}

void	set_hook(t_mlx *mlxs)
{
	mlx_mouse_hook(mlxs->display->win_p, mouse_hook, mlxs);
	mlx_hook(mlxs->display->win_p, 2, 1LL << 0, close_window, mlxs);
}
