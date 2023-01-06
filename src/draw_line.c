#include "fdf.h"
#include "menu.h"
#include "color.h"

static bool	is_out_of_menu(size_t y, size_t x)
{
	return (!(WIN_MARGIN <= y && y < WIN_MARGIN + MENU_HEIGHT && \
			WIN_MARGIN <= x && x < WIN_MARGIN + MENU_WIDTH));
}

static void	set_sxy(t_xy *sign, t_point from, t_point to)
{
	sign->x = -1;
	if (from.x < to.x)
		sign->x = 1;
	sign->y = -1;
	if (from.y < to.y)
		sign->y = 1;
}

static void	draw_line_by_bresenham(\
			t_img *img, const t_point from, const t_point to)
{
	const t_xy	delta = {.x = abs(to.x - from.x), .y = abs(to.y - from.y)};
	t_xy		sign;
	t_point		current;
	int			err;
	int			err2;

	set_sxy(&sign, from, to);
	err = delta.x - delta.y;
	current = from;
	while (!(current.x == to.x && current.y == to.y))
	{
		if (is_out_of_menu(current.y, current.x))
			my_mlx_pixel_put(img, current.y, current.x, \
							get_current_color(current, from, to, delta));
		err2 = 2 * err;
		if (err2 > -delta.y)
		{
			err -= delta.y;
			current.x += sign.x;
		}
		if (err2 < delta.x)
		{
			err += delta.x;
			current.y += sign.y;
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
		draw_line_by_bresenham(mlxs->img, from, to);
	}
	if (x + 1 < mlxs->map->width)
	{
		calc_and_rotate(mlxs, &to, x + 1, y);
		draw_line_by_bresenham(mlxs->img, from, to);
	}
	if (y + 1 == mlxs->map->height && x + 1 == mlxs->map->width && \
		is_out_of_menu(from.y, from.x))
		my_mlx_pixel_put(mlxs->img, from.y, from.x, from.color);
}
