#include "fdf.h"
#include <math.h>

void	calc_coordinates(t_point *point, size_t x, size_t y, size_t z)
{
	point->x = PIXEL_SIZE * x;
	point->y = PIXEL_SIZE * y;
	point->z = z * HEIGHT_MAGNIFICATION;
}

static double	degree_to_radian(int degree)
{
	return ((double)degree * PI / 180.0);
}

void	rotate_to_isometric_projection(t_mlx *mlxs, t_point *point)
{
	const double	cos_radian = degree_to_radian(ANGLE);
	const double	sin_radian = degree_to_radian(ANGLE);
	t_point			tmp;

	tmp.x = (point->x - point->y) * cos(cos_radian);
	tmp.y = (point->x + point->y) * sin(sin_radian) - point->z;
	point->x = tmp.x + mlxs->delta_x;
	point->y = tmp.y + mlxs->delta_y;
}

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

void	draw_line_by_bresenham(t_img *img, t_point from, t_point to, int color)
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
