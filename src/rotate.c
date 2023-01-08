#include "fdf.h"
#include "color.h"
#include "menu.h"
#include <math.h>

static double	degree_to_radian(double degree)
{
	return (degree * PI / 180.0);
}

static void	rotate_x_axis(const t_mlx *mlxs, t_point *point, const t_point tmp)
{
	const int		angle = mlxs->rotate_x_angle % 360;
	const double	radian = degree_to_radian(angle);

	point->y = tmp.y * cos(radian) + tmp.z * sin(radian);
	point->z = -tmp.y * sin(radian) + tmp.z * cos(radian);
}

static void	rotate_y_axis(const t_mlx *mlxs, t_point *point, const t_point tmp)
{
	const int		angle = mlxs->rotate_y_angle % 360;
	const double	radian = degree_to_radian(angle);

	point->x = tmp.x * cos(radian) + tmp.z * sin(radian);
	point->z = -tmp.x * sin(radian) + tmp.z * cos(radian);
}

static void	rotate_to_isometric_projection(t_point *point, const t_point tmp)
{
	const double	radian = degree_to_radian(ANGLE_ISO);

	point->x = (tmp.x - tmp.y) * cos(radian);
	point->y = (tmp.x + tmp.y) * sin(radian) - point->z;
}

void	calc_and_rotate(\
			const t_mlx *mlxs, t_point *point, const size_t x, const size_t y)
{
	point->x = x * mlxs->points_distance;
	point->y = y * mlxs->points_distance;
	point->z = mlxs->map->height_map[y][x] * mlxs->height_emphasis;
	point->x -= (mlxs->map->width * mlxs->points_distance) / 2;
	point->y -= (mlxs->map->height * mlxs->points_distance) / 2;
	if (mlxs->map->color_map[y][x] == NONE_COLOR)
		set_default_color(mlxs, point, point->z);
	else
		point->color = mlxs->map->color_map[y][x];
	rotate_x_axis(mlxs, point, *point);
	rotate_y_axis(mlxs, point, *point);
	if (mlxs->is_iso)
		rotate_to_isometric_projection(point, *point);
	point->x += WIN_WIDTH - (WIN_WIDTH - (WIN_MARGIN + MENU_WIDTH)) / 2;
	point->x += mlxs->delta_x;
	point->y += WIN_HEIGHT / 2;
	point->y += mlxs->delta_y;
}
