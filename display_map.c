#include "fdf.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h> // todo: printf -> ft_printf

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

void	calc_coordinates(t_point *point, size_t x, size_t y, size_t z)
{
	point->x = PIXEL_SIZE * x;
	point->y = PIXEL_SIZE * y;
	point->z = z * HEIGHT_MAGNIFICATION;
}

double	degree_to_radian(int degree)
{
	return ((double)degree * PI / 180.0);
}

void	rotate_to_isometric_projection(t_point *point)
{
	const double	cos_radian = degree_to_radian(30);
	const double	sin_radian = degree_to_radian(30);
	t_point	tmp;

	tmp.x = (point->x - point->y) * cos(cos_radian);
	tmp.y = (point->x + point->y) * sin(sin_radian) - point->z;
	point->x = tmp.x + SHIFT_X;
	point->y = tmp.y + SHIFT_Y;
}

void	draw_line_by_bresenham(t_point from, t_point to, t_img_data *img)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	err2;

	if (from.x < to.x)
		sx = 1;
	else
		sx = -1;
	if (from.y < to.y)
		sy = 1;
	else
		sy = -1;
	dx = abs(to.x - from.x);
	dy = abs(to.y - from.y);
	err = dx - dy;
	while (!(from.x == to.x && from.y == to.y))
	{
		my_mlx_pixel_put(img, from.x, from.y, 0x0061ff76);
		err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			from.x += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			from.y += sy;
		}
	}
}

void	draw_line_to_right_and_down(t_map *map, t_img_data *img, size_t x, size_t y)
{
	t_point	from;
	t_point	to;

	calc_coordinates(&from, x, y, map->height_map[y][x]);
	rotate_to_isometric_projection(&from);
	if (y + 1 < map->height)
	{
		calc_coordinates(&to, x, y + 1, map->height_map[y + 1][x]);
		rotate_to_isometric_projection(&to);
		draw_line_by_bresenham(from, to, img);
	}
	if (x + 1 < map->width)
	{
		calc_coordinates(&to, x + 1, y, map->height_map[y][x + 1]);
		rotate_to_isometric_projection(&to);
		draw_line_by_bresenham(from, to, img);
	}
	if (y + 1 == map->height && x + 1 == map->width)
		my_mlx_pixel_put(img, from.x, from.y, 0x0061ff76);
}

void	set_image(t_map *map, t_img_data *img)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_line_to_right_and_down(map, img, x, y);
			x++;
		}
		y++;
	}
}

void	display_map(t_map *map)
{
	void		*mlx_p;
	void		*mlx_window_p;
	t_img_data	img;

	debug_map(map);
	mlx_p = mlx_init();
	mlx_window_p = mlx_new_window(mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx@hiabe");
	img.img = mlx_new_image(mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	set_image(map, &img);
	mlx_put_image_to_window(mlx_p, mlx_window_p, img.img, 0, 0);
	mlx_loop(mlx_p);
	// mlx_destroy_image(mlx_p, img.img);
}
