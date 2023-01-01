#include "fdf.h"
#include "hook.h"

static void	set_t_mlxs(\
				t_mlx *mlxs, t_display *display, t_img *img, t_info *info)
{
	mlxs->display = display;
	mlxs->img = img;
	mlxs->map = info->map;
	mlxs->data = info->data;
	mlxs->delta_x = 200;
	mlxs->delta_y = 300;
}

static void	set_window(t_mlx *mlxs, char *my_title)
{
	mlxs->display->mlx_p = mlx_init();
	// error
	mlxs->display->win_p = mlx_new_window(\
						mlxs->display->mlx_p, WIN_WIDTH, WIN_HEIGHT, my_title);
	// error
}

void	set_image(t_mlx *mlxs)
{
	mlxs->img->img = mlx_new_image(mlxs->display->mlx_p, WIN_WIDTH, WIN_HEIGHT);
	// error
	mlxs->img->addr = mlx_get_data_addr(\
						mlxs->img->img, &mlxs->img->bits_per_pixel, \
						&mlxs->img->line_length, &mlxs->img->endian);
	// error
}

static void	set_hook(t_mlx *mlxs)
{
	const long long	exit_mask = 1LL << 17;

	mlx_mouse_hook(mlxs->display->win_p, mouse_hook, mlxs);
	mlx_key_hook(mlxs->display->win_p, key_hook, mlxs);
	mlx_hook(mlxs->display->win_p, EXIT_EVENT, exit_mask, close_window, mlxs);
}

void	display_map(t_info *info)
{
	t_mlx		mlxs;
	t_display	display;
	char		*my_title;
	t_img		img;

	debug_map(info->map); // to do: erase
	set_t_mlxs(&mlxs, &display, &img, info);
	my_title = "FdF@hiabe";
	set_window(&mlxs, my_title);
	set_image(&mlxs);
	draw_image(&mlxs);
	set_hook(&mlxs);
	mlx_loop(mlxs.display->mlx_p);
}
