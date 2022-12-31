#include "fdf.h"

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

static void	draw_line_right_down(t_mlx *mlxs, size_t x, size_t y)
{
	t_point	from;
	t_point	to;

	calc_coordinates(&from, x, y, mlxs->map->height_map[y][x]);
	rotate_to_isometric_projection(mlxs, &from);
	if (y + 1 < mlxs->map->height)
	{
		calc_coordinates(&to, x, y + 1, mlxs->map->height_map[y + 1][x]);
		rotate_to_isometric_projection(mlxs, &to);
		draw_line_by_bresenham(mlxs->img, from, to, 0);
	}
	if (x + 1 < mlxs->map->width)
	{
		calc_coordinates(&to, x + 1, y, mlxs->map->height_map[y][x + 1]);
		rotate_to_isometric_projection(mlxs, &to);
		draw_line_by_bresenham(mlxs->img, from, to, 0);
	}
	if (y + 1 == mlxs->map->height && x + 1 == mlxs->map->width)
		my_mlx_pixel_put(mlxs->img, from.y, from.x, 0x0061ff76);
}

static void	draw_lines(t_mlx *mlxs)
{
	size_t	x;
	size_t	y;

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
}

void	set_image(t_mlx *mlxs)
{
	mlxs->img->img = mlx_new_image(mlxs->display->mlx_p, WIN_WIDTH, WIN_HEIGHT);
	// error
	mlxs->img->addr = mlx_get_data_addr(\
						mlxs->img->img, &mlxs->img->bits_per_pixel, \
						&mlxs->img->line_length, &mlxs->img->endian);
	// error
	draw_lines(mlxs);
}
