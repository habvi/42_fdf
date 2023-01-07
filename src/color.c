#include "fdf.h"
#include "color.h"

static double	get_percent(const int start, const int end, const int current)
{
	double	start_to_current;
	double	start_to_end;

	start_to_current = current - start;
	start_to_end = end - start;
	if (start_to_end == 0)
		return (1.0);
	else
		return (start_to_current / start_to_end);
}

static int	get_light(const int start, const int end, const double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int	get_current_color(const t_point current, t_point start, \
						t_point end, const t_xy delta)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percent = get_percent(start.x, end.x, current.x);
	else
		percent = get_percent(start.y, end.y, current.y);
	red = get_light((start.color >> RED_SHIFT) & COLOR_MASK, \
					(end.color >> RED_SHIFT) & COLOR_MASK, percent);
	green = get_light((start.color >> GREEN_SHIFT) & COLOR_MASK, \
					(end.color >> GREEN_SHIFT) & COLOR_MASK, percent);
	blue = get_light(start.color & COLOR_MASK, end.color & COLOR_MASK, percent);
	return ((red << RED_SHIFT) | (green << GREEN_SHIFT) | blue);
}

void	set_default_color(const t_mlx *mlxs, t_point *point, const int z)
{
	const double	percent = get_percent(\
		mlxs->z_min, mlxs->z_max, z / mlxs->height_emphasis);

	if (percent < DEFAULT_COLOR_BLOCK)
		point->color = COLOR_PINK;
	else if (percent < DEFAULT_COLOR_BLOCK * 2)
		point->color = COLOR_YELLOW;
	else if (percent < DEFAULT_COLOR_BLOCK * 3)
		point->color = COLOR_GREEN;
	else
		point->color = COLOR_BLUE;
}
