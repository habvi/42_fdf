#include "fdf.h"

void	set_t_mlxs(\
				t_mlx *mlxs, t_display *display, t_img *img, t_info *info)
{
	mlxs->display = display;
	mlxs->img = img;
	mlxs->map = info->map;
	mlxs->data = info->data;
	mlxs->delta_x = 200;
	mlxs->delta_y = 300;
}

void	set_window(t_mlx *mlxs, char *my_title)
{
	mlxs->display->mlx_p = mlx_init();
	// error
	mlxs->display->win_p = mlx_new_window(\
						mlxs->display->mlx_p, WIN_WIDTH, WIN_HEIGHT, my_title);
	// error
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
	set_hook(&mlxs);
	mlx_put_image_to_window(mlxs.display->mlx_p, mlxs.display->win_p, mlxs.img->img, 0, 0);
	mlx_loop(display.mlx_p);
}
