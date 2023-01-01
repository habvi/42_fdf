#include "fdf.h"
#include "hook.h"
#include <stdio.h> // to do: printf -> ft_printf

// static bool	is_rolled_mouse(t_mouse mouse_code)
// {
// 	return (mouse_code == MOUSE_LEFT || mouse_code == MOUSE_RIGHT || \
// 			mouse_code == MOUSE_UP || mouse_code == MOUSE_DOWN);
// }

// rotate, HEIGHT_MAGNIFICATION ?
// static void	move_image(t_mouse mouse_code, t_mlx *mlxs)
// {
// 	if (mouse_code == MOUSE_LEFT)
// 	else if (mouse_code == MOUSE_RIGHT)
// 	else if (mouse_code == MOUSE_UP)
// 	else if (mouse_code == MOUSE_DOWN)
// }

int	mouse_hook(t_mouse mouse_code, int x, int y, t_mlx *mlxs)
{
	printf("mousecode : %d, (y, x) = (%d, %d)\n", mouse_code, y, x);
	(void)mlxs;
	// if (is_rolled_mouse(mouse_code))
	// {
	// 	move_image(mouse_code, mlxs);
	// 	mlx_destroy_image(mlxs->display->mlx_p, mlxs->img->img);
	// 	set_image(mlxs);
	// 	draw_image(mlxs);
	// }
	return (SUCCESS);
}
