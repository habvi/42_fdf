#include "fdf.h"
#include "color.h"
#include "menu.h"

static void	set_coordinate(\
			const t_mlx *mlxs, t_point *point, const size_t x, const size_t y)
{
	point->x = x * mlxs->points_distance;
	point->y = y * mlxs->points_distance;
	point->z = mlxs->map->height_map[y][x] * mlxs->height_emphasis;
	point->x -= (mlxs->map->width * mlxs->points_distance) / 2;
	point->y -= (mlxs->map->height * mlxs->points_distance) / 2;
}

static void	set_color(\
			const t_mlx *mlxs, t_point *point, const size_t x, const size_t y)
{
	if (mlxs->map->color_map[y][x] == NONE_COLOR)
		set_default_color(mlxs, point, point->z);
	else
		point->color = mlxs->map->color_map[y][x];
}

static void	set_rotate(const t_mlx *mlxs, t_point *point)
{
	rotate_x_axis(mlxs, point, *point);
	rotate_y_axis(mlxs, point, *point);
	rotate_z_axis(mlxs, point, *point);
	if (mlxs->is_iso)
		rotate_to_isometric_projection(point, *point);
}

static void	adjust_point(const t_mlx *mlxs, t_point *point)
{
	point->x += WIN_WIDTH - (WIN_WIDTH - (WIN_MARGIN + MENU_WIDTH)) / 2;
	point->x += mlxs->delta_x;
	point->y += WIN_HEIGHT / 2;
	point->y += mlxs->delta_y;
}

void	set_point_info(\
			const t_mlx *mlxs, t_point *point, const size_t x, const size_t y)
{
	set_coordinate(mlxs, point, x, y);
	set_color(mlxs, point, x, y);
	set_rotate(mlxs, point);
	adjust_point(mlxs, point);
}
