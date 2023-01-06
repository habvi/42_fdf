#include <math.h>
#include "fdf.h"
#include "color.h"

static double	degree_to_radian(double degree)
{
	return (degree * PI / 180.0);
}

static void	rotate_x_axis(t_mlx *mlxs, t_point *point, const t_point tmp)
{
	const int		angle = mlxs->rotate_x_angle % 360;
	const double	radian = degree_to_radian(angle);

	point->y = tmp.y * cos(radian) + tmp.z * sin(radian);
	point->z = -tmp.y * sin(radian) + tmp.z * cos(radian);
}

static void	rotate_y_axis(t_mlx *mlxs, t_point *point, t_point tmp)
{
	const int		angle = mlxs->rotate_y_angle % 360;
	const double	radian = degree_to_radian(angle);

	point->x = tmp.x * cos(radian) + tmp.z * sin(radian);
	point->z = -tmp.x * sin(radian) + tmp.z * cos(radian);
}

static void	rotate_to_isometric_projection(t_point *point)
{
	const double	radian = degree_to_radian(ANGLE_ISO);
	t_point			tmp;

	tmp.x = (point->x - point->y) * cos(radian);
	tmp.y = (point->x + point->y) * sin(radian) - point->z;
	point->x = tmp.x;
	point->y = tmp.y;
}

void	calc_and_rotate(t_mlx *mlxs, t_point *point, size_t x, size_t y)
{
	point->x = mlxs->points_distance * x;
	point->y = mlxs->points_distance * y;
	point->z = mlxs->map->height_map[y][x] * mlxs->height_emphasis;
	if (mlxs->is_iso)
	{
		rotate_x_axis(mlxs, point, *point);
		rotate_y_axis(mlxs, point, *point);
		rotate_to_isometric_projection(point);
	}
	point->x += mlxs->delta_x;
	point->y += mlxs->delta_y;
if (mlxs->map->height_map[y][x] == 0)
		point->color = COLOR_PINK;
	else
		point->color = COLOR_GREEN;
}
