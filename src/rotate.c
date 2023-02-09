#include <math.h>
#include "fdf.h"
#include "draw.h"

static double	degree_to_radian(double degree)
{
	return (degree * PI / 180.0);
}

void	rotate_x_axis(const t_mlx *mlxs, t_point *point, const t_point tmp)
{
	const int		angle = mlxs->rotate_x_angle % 360;
	const double	radian = degree_to_radian(angle);

	point->y = tmp.y * cos(radian) + tmp.z * sin(radian);
	point->z = -tmp.y * sin(radian) + tmp.z * cos(radian);
}

void	rotate_y_axis(const t_mlx *mlxs, t_point *point, const t_point tmp)
{
	const int		angle = mlxs->rotate_y_angle % 360;
	const double	radian = degree_to_radian(angle);

	point->x = tmp.x * cos(radian) + tmp.z * sin(radian);
	point->z = -tmp.x * sin(radian) + tmp.z * cos(radian);
}

void	rotate_z_axis(const t_mlx *mlxs, t_point *point, const t_point tmp)
{
	const int		angle = mlxs->rotate_z_angle % 360;
	const double	radian = degree_to_radian(angle);

	point->x = tmp.x * cos(radian) - tmp.y * sin(radian);
	point->y = tmp.x * sin(radian) + tmp.y * cos(radian);
}

void	rotate_to_isometric_projection(t_point *point, const t_point tmp)
{
	const double	radian = degree_to_radian(ANGLE_ISO);

	point->x = (tmp.x - tmp.y) * cos(radian);
	point->y = (tmp.x + tmp.y) * sin(radian) - point->z;
}
