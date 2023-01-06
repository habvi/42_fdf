#include "fdf.h"
#include "menu.h"

static bool	is_in_window(int y, int x)
{
	return (0 <= y && y < WIN_HEIGHT && 0 <= x && x < WIN_WIDTH);
}

void	my_mlx_pixel_put(t_img *img, int y, int x, int color)
{
	char	*dst;
	int		offset;

	if (!is_in_window(y, x))
		return ;
	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

static void	draw_menu_background(t_mlx *mlxs)
{
	size_t	x;
	size_t	y;

	y = WIN_MARGIN;
	while (y < WIN_MARGIN + MENU_HEIGHT)
	{
		x = WIN_MARGIN;
		while (x < WIN_MARGIN + MENU_WIDTH)
		{
			my_mlx_pixel_put(mlxs->img, y, x, MENU_BG_COLOR);
			x++;
		}
		y++;
	}
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

void	draw_image(t_mlx *mlxs)
{
	size_t	x;
	size_t	y;

	draw_menu_background(mlxs);
	y = 0;
	while (y < mlxs->map->height)
	{
		x = 0;
		while (x < mlxs->map->width)
		{
			draw_line_right_down(mlxs, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(\
			mlxs->display->mlx_p, mlxs->display->win_p, mlxs->img->img, 0, 0);
	draw_menu_string(mlxs);
}
