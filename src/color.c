#include "fdf.h"
#include "color.h"

static double	get_percent(int start, int end, int current)
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

static int	get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int	get_current_color(t_point current, t_point start, \
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
