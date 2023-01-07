#include "fdf.h"
#include "../libft/include/libft.h"
#include "../minilibx/mlx.h"
#include "hook.h"
#include <X11/X.h>

static void	init_t_mlxs(\
			t_mlx *mlxs, t_display *display, t_img *img, const t_info *info)
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
				ft_min_double((WIN_HEIGHT - 2 * start_y) / mlxs->map->height, \
								(WIN_WIDTH - 2 * start_x) / mlxs->map->width);
	mlxs->height_emphasis = DEFAULT_HEIGHT_EMPHASIS;
	mlxs->delta_y = start_y;
	mlxs->delta_x = start_x * 2;
	mlxs->rotate_x_angle = 0;
	mlxs->rotate_y_angle = 0;
}

static void	set_window(const t_mlx *mlxs)
{
	mlxs->display->mlx_p = mlx_init();
	// error
	mlxs->display->win_p = mlx_new_window(\
						mlxs->display->mlx_p, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	// error
}

static void	set_hook(const t_mlx *mlxs)
{
	void	*win_p;
	void	*params;

	win_p = mlxs->display->win_p;
	params = (void *)mlxs;
	mlx_mouse_hook(win_p, mouse_hook, params);
	mlx_key_hook(win_p, key_hook, params);
	mlx_hook(win_p, FocusIn, FocusChangeMask, minimize_window, params);
	mlx_hook(win_p, DestroyNotify, StructureNotifyMask, close_window, params);
}

void	display_map(const t_info *info)
{
	t_mlx		mlxs;
	t_display	display;
	t_img		img;

	init_t_mlxs(&mlxs, &display, &img, info);
	set_window(&mlxs);
	set_image(&mlxs);
	draw_image(&mlxs);
	set_hook(&mlxs);
	mlx_loop(mlxs.display->mlx_p);
}
