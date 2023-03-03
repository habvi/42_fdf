#ifndef FDF_H
# define FDF_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_list	t_list;

typedef enum e_status {
	SUCCESS = 0,
	ERROR = 1
}	t_status;

typedef struct s_map {
	size_t	width;
	size_t	height;
	int		**height_map;
	int64_t	**color_map;
}	t_map;

typedef struct s_info {
	t_list	*head;
	t_list	*tail;
	t_map	*map;
	int		z_min;
	int		z_max;
}	t_info;

typedef struct s_display {
	void	*mlx_p;
	void	*win_p;
}	t_display;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_xy {
	int	x;
	int	y;
}	t_xy;

typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_mlx {
	int			win_height;
	int			win_width;
	t_display	*display;
	t_img		*img;
	t_map		*map;
	t_list		*data;
	int			z_min;
	int			z_max;
	bool		is_iso;
	double		zoom;
	double		points_distance;
	double		height_emphasis;
	int			delta_x;
	int			delta_y;
	int			rotate_x_angle;
	int			rotate_y_angle;
	int			rotate_z_angle;
}	t_mlx;

// exit.c
void	error_exit(const uint8_t error_code);
void	error_exit_errno(const char *msg);
void	clear_before_exit(\
			const t_info *info, const size_t n, const uint8_t error_code);
void	exit_mlx_p(const t_mlx *mlxs);
void	exit_win_p(const t_mlx *mlxs);
void	exit_img_p(const t_mlx *mlxs);

// args.c
bool	check_args(const int argc, char *const argv[], uint8_t *erorr_code);

// read.c
void	read_map(const char *filepath, t_info *info, size_t *line_count);

// clear.c
void	clear_split_list(char **list);
void	clear_data(t_list *data);
void	clear_map_to_n(const t_map *map, const size_t n);
int		close_window(const t_mlx *mlxs);

// parse.c
void	parse_map(t_info *info, const size_t line_count);

// convert.c
void	convert_map_height_and_color(t_info *info, char **list, const size_t i);

// set_data.c
void	set_data_to_map(t_info *info, t_list *data, const size_t i);

// display_map.c
void	display_map(const t_info *info);

// image.c
bool	is_in_window(const int y, const int x);
void	my_mlx_pixel_put(t_img *img, const int y, const int x, const int color);
void	set_image(t_mlx *mlxs);
void	draw_image(const t_mlx *mlxs);

// draw_line.c
void	draw_line_right_down(const t_mlx *mlxs, const size_t x, const size_t y);

// set_point.c
void	set_point_info(\
			const t_mlx *mlxs, t_point *point, const size_t x, const size_t y);

// rotate.c
void	rotate_x_axis(const t_mlx *mlxs, t_point *point, const t_point tmp);
void	rotate_y_axis(const t_mlx *mlxs, t_point *point, const t_point tmp);
void	rotate_z_axis(const t_mlx *mlxs, t_point *point, const t_point tmp);
void	rotate_to_isometric_projection(t_point *point, const t_point tmp);

#endif
