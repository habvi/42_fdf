#include "fdf.h"

static void	set_sxy(t_xy *sxy, t_point *from, t_point *to)
{
	if (from->x < to->x)
		sxy->x = 1;
	else
		sxy->x = -1;
	if (from->y < to->y)
		sxy->y = 1;
	else
		sxy->y = -1;
}

static void	draw_line_by_bresenham(t_img *img, t_point from, t_point to, int color)
{
	const t_xy	dxy = {.x = abs(to.x - from.x), .y = abs(to.y - from.y)};
	t_xy		sxy;
	int			err;
	int			err2;

	set_sxy(&sxy, &from, &to);
	err = dxy.x - dxy.y;
	while (!(from.x == to.x && from.y == to.y))
	{
		(void)color;
		my_mlx_pixel_put(img, from.y, from.x, 0x0061ff76);
		err2 = 2 * err;
		if (err2 > -dxy.y)
		{
			err -= dxy.y;
			from.x += sxy.x;
		}
		if (err2 < dxy.x)
		{
			err += dxy.x;
			from.y += sxy.y;
		}
	}
}

void	draw_line_right_down(t_mlx *mlxs, size_t x, size_t y)
{
	t_point	from;
	t_point	to;

	calc_and_rotate(mlxs, &from, x, y);
	if (y + 1 < mlxs->map->height)
	{
		calc_and_rotate(mlxs, &to, x, y + 1);
		draw_line_by_bresenham(mlxs->img, from, to, 0);
	}
	if (x + 1 < mlxs->map->width)
	{
		calc_and_rotate(mlxs, &to, x + 1, y);
		draw_line_by_bresenham(mlxs->img, from, to, 0);
	}
	if (y + 1 == mlxs->map->height && x + 1 == mlxs->map->width) // out of menu
		my_mlx_pixel_put(mlxs->img, from.y, from.x, 0x0061ff76);
}
