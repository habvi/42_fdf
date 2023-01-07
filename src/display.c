#include "fdf.h"
#include "hook.h"
#include <X11/X.h>

static void	init_t_mlxs(\
				t_mlx *mlxs, t_display *display, t_img *img, t_info *info)
{
	const double	start_y = WIN_HEIGHT * DEFAULT_ZOOM;
	const double	start_x = WIN_WIDTH * DEFAULT_ZOOM;

	mlxs->display = display;
	mlxs->img = img;
	mlxs->map = info->map;
	mlxs->data = info->data;
	mlxs->is_iso = true;
	mlxs->zoom = DEFAULT_ZOOM;
	mlxs->points_distance = \
				ft_min_double((WIN_HEIGHT - 2 * start_y) / (double)mlxs->map->height, \
								(WIN_WIDTH - 2 * start_x) / (double)mlxs->map->width);
	mlxs->height_emphasis = DEFAULT_HEIGHT_EMPHASIS;
	mlxs->delta_y = start_y;
	mlxs->delta_x = start_x * 2;
	mlxs->rotate_x_angle = 0;
	mlxs->rotate_y_angle = 0;
}

static void	set_window(t_mlx *mlxs, char *my_title)
{
	mlxs->display->mlx_p = mlx_init();
	// error
	mlxs->display->win_p = mlx_new_window(\
						mlxs->display->mlx_p, WIN_WIDTH, WIN_HEIGHT, my_title);
	// error
}

static void	set_hook(t_mlx *mlxs)
{
	void	*win_p;

	win_p = mlxs->display->win_p;
	mlx_mouse_hook(win_p, mouse_hook, mlxs);
	mlx_key_hook(win_p, key_hook, mlxs);
	mlx_hook(win_p, FocusIn, FocusChangeMask, minimize_window, mlxs);
	mlx_hook(win_p, DestroyNotify, StructureNotifyMask, close_window, mlxs);
}

void	display_map(t_info *info)
{
	t_mlx		mlxs;
	t_display	display;
	t_img		img;

	init_t_mlxs(&mlxs, &display, &img, info);
	set_window(&mlxs, WIN_TITLE);
	set_image(&mlxs);
	draw_image(&mlxs);
	set_hook(&mlxs);
	mlx_loop(mlxs.display->mlx_p);
}
