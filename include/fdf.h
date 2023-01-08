#ifndef FDF_H
# define FDF_H

// # include <unistd.h> // close, read, write
# include <stdlib.h> // malloc, free, exit
// # include <stdio.h> // perror
# include <string.h> // strerror
# include <errno.h>
# include <stdbool.h>

# include "../libft/include/list.h"

# define ERR_MSG_FILEPATH			"invalid filepath"
# define ERR_MSG_FILE_EXTENSION		"invalid file's extension"
# define ERR_MSG_ARGS				"invalid number of arguments"
# define ERR_MSG_INVALID_MAP		"invalid map"
# define ERR_MSG_MALLOC				"malloc"
# define ERR_MSG_EMPTY				"empty file"
# define ERR_MSG_MAP_WIDTH			"invalid map width"
# define ERR_MLX					"from mlx"

# define FILE_EXTENSION				".fdf"
# define OPEN_ERROR					-1
# define NONE_COLOR					-1
# define OVER_MAX_DIGIT				12

# define WIN_TITLE					"FdF@hiabe"
# define WIN_HEIGHT					720
# define WIN_WIDTH					1280

# define DEFAULT_ZOOM				(0.25)
# define DEFAULT_HEIGHT_EMPHASIS	1

# define PI							(3.14159265358979323846264338327950288)
# define ANGLE_ISO					30

typedef enum e_status {
	SUCCESS = 0,
	ERROR = 1
}	t_status;

typedef struct s_map {
	size_t	width;
	size_t	height;
	int		**height_map;
	int		**color_map;
}	t_map;

typedef struct s_info {
	t_list			*data;
	const t_list	*head;
	t_map			*map;
	int				z_min;
	int				z_max;
}	t_info;

typedef struct s_display {
	void	*mlx_p;
	void	*win_p;
}	t_display;

# include "debug.h" // to do: erase

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
}	t_mlx;

// exit.c
void	error_exit(const char *msg, void *ptr, const int status);
void	clear_before_exit(const t_info *info, const char *msg, const size_t n);
void	exit_mlx_p(const t_mlx *mlxs);
void	exit_win_p(const t_mlx *mlxs);
void	exit_img_p(const t_mlx *mlxs);

// args.c
int		check_args(const int argc, const char *argv[]);

// read.c
size_t	read_map(const int fd, t_list **data);

// clear.c
void	clear_split_list(char **list);
void	clear_data(t_list *data);
void	clear_map_to_n(const t_map *map, const size_t n);
int		close_window(const t_mlx *mlxs);

// parse.c
void	parse_map(const t_info *info, const size_t line_count);

// convert.c
void	convert_map_height_and_color(\
					const t_info *info, const char **list, const size_t i);

// set_data.c
void	set_data_to_map(const t_info *info, const t_list *data, const size_t i);

// display_map.c
void	display_map(const t_info *info);

// image.c
bool	is_in_window(const int y, const int x);
void	my_mlx_pixel_put(t_img *img, const int y, const int x, const int color);
void	set_image(const t_mlx *mlxs);
void	draw_image(const t_mlx *mlxs);

// draw_line.c
void	draw_line_right_down(const t_mlx *mlxs, const size_t x, const size_t y);

// rotate.c
void	calc_and_rotate(\
			const t_mlx *mlxs, t_point *point, const size_t x, const size_t y);

#endif
