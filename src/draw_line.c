#include "fdf.h"
#include "menu.h"
#include "color.h"

static bool	is_out_of_menu(const size_t y, const size_t x)
{
	return (!(WIN_MARGIN <= y && y < WIN_MARGIN + MENU_HEIGHT && \
			WIN_MARGIN <= x && x < WIN_MARGIN + MENU_WIDTH));
}

static void	set_sxy(\
			t_xy *sign, const t_point from, const t_point to, t_point *current)
{
	sign->x = -1;
	if (from.x < to.x)
		sign->x = 1;
	sign->y = -1;
	if (from.y < to.y)
		sign->y = 1;
	*current = from;
}

static void	update_err_current(\
			int err[2], const t_xy delta, const t_xy sign, t_point *current)
{
	err[1] = 2 * err[0];
	if (err[1] > -delta.y)
	{
		err[0] -= delta.y;
		current->x += sign.x;
	}
	if (err[1] < delta.x)
	{
		err[0] += delta.x;
		current->y += sign.y;
	}
}

static void	draw_line_by_bresenham(\
						t_mlx *mlxs, const t_point from, const t_point to)
{
	const t_xy	delta = {.x = abs(to.x - from.x), .y = abs(to.y - from.y)};
	t_xy		sign;
	t_point		current;
	int			err[2];
	int			color;

	set_sxy(&sign, from, to, &current);
	err[0] = delta.x - delta.y;
	while (!(current.x == to.x && current.y == to.y))
	{
		if (is_out_of_menu(current.y, current.x) && \
			is_in_window(current.y, current.x) && \
			mlxs->counter % DRAW_INTERVAL == 0) // to do: change each density
		{
			color = get_current_color(current, from, to, delta);
			my_mlx_pixel_put(mlxs->img, current.y, current.x, color);
		}
		mlxs->counter++;
		update_err_current(err, delta, sign, &current);
	}
}

void	draw_line_right_down(const t_mlx *mlxs, const size_t x, const size_t y)
{
	t_point	from;
	t_point	to;

	calc_and_rotate(mlxs, &from, x, y);
	if (y + 1 < mlxs->map->height)
	{
		calc_and_rotate(mlxs, &to, x, y + 1);
		draw_line_by_bresenham((t_mlx *)mlxs, from, to);
	}
	if (x + 1 < mlxs->map->width)
	{
		calc_and_rotate(mlxs, &to, x + 1, y);
		draw_line_by_bresenham((t_mlx *)mlxs, from, to);
	}
	if (y + 1 == mlxs->map->height && x + 1 == mlxs->map->width && \
		is_out_of_menu(from.y, from.x) && is_in_window(from.y, from.x))
		my_mlx_pixel_put(mlxs->img, from.y, from.x, from.color);
}
