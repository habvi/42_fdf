#include <X11/X.h>
#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include "hook.h"

static void	init_z(t_mlx *mlxs, const t_info *info)
{
	const double	div = (info->z_max - info->z_min) / (WIN_HEIGHT * 0.1);
	size_t			y;
	size_t			x;

	mlxs->z_min = info->z_min / div;
	mlxs->z_max = info->z_max / div;
	if (div)
	{
		y = 0;
		while (y < mlxs->map->height)
		{
			x = 0;
			while (x < mlxs->map->width)
			{
				mlxs->map->height_map[y][x] /= div;
				x++;
			}
			y++;
		}
	}
}

static void	init_t_mlxs(\
			t_mlx *mlxs, t_display *display, t_img *img, const t_info *info)
{
	static const double	start_y = WIN_HEIGHT * DEFAULT_ZOOM;
	static const double	start_x = WIN_WIDTH * DEFAULT_ZOOM;

	mlxs->display = display;
	mlxs->img = img;
	mlxs->map = info->map;
	mlxs->data = info->head;
	init_z(mlxs, info);
	mlxs->is_iso = true;
	mlxs->zoom = DEFAULT_ZOOM;
	mlxs->points_distance = \
				ft_min_double((WIN_HEIGHT - 2 * start_y) / mlxs->map->height, \
								(WIN_WIDTH - 2 * start_x) / mlxs->map->width);
	mlxs->height_emphasis = DEFAULT_HEIGHT_EMPHASIS;
	mlxs->delta_y = 0;
	mlxs->delta_x = 0;
	mlxs->rotate_x_angle = 0;
	mlxs->rotate_y_angle = 0;
	mlxs->rotate_z_angle = 0;
}

static void	set_window(t_mlx *mlxs)
{
	mlxs->display->mlx_p = mlx_init();
	if (mlxs->display->mlx_p == NULL)
		exit_mlx_p(mlxs);
	mlxs->display->win_p = mlx_new_window(\
						mlxs->display->mlx_p, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (mlxs->display->win_p == NULL)
		exit_win_p(mlxs);
}

static void	set_hook(t_mlx *mlxs)
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
	if (mlxs.img->img == NULL)
		exit_img_p(&mlxs);
	draw_image(&mlxs);
	set_hook(&mlxs);
	mlx_loop(mlxs.display->mlx_p);
}
