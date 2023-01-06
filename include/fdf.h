#ifndef FDF_H
# define FDF_H

# include <fcntl.h> // open
// # include <unistd.h> // close, read, write
# include <stdlib.h> // malloc, free, exit
// # include <stdio.h> // perror
# include <string.h> // strerror
# include <errno.h> // to do: fix
# include <stdbool.h>

// # include "libft.h"
// # include "list.h"
// # include "minilibx/mlx.h"

# include "../libft/include/libft.h"
# include "../libft/include/list.h"
# include "../minilibx/mlx.h"

# define ERR_MSG_FILEPATH			"invalid filepath"
# define ERR_MSG_FILE_EXTENSION		"invalid file's extension"
# define ERR_MSG_ARGS				"invalid number of arguments"
# define ERR_MSG_INVALID_MAP		"invalid map"
# define ERR_MSG_MALLOC				"malloc"
# define ERR_MSG_EMPTY				"empty file"
# define ERR_MSG_MAP_HEIGHT			"invalid map height"
# define ERR_MSG_MAP_WIDTH			"invalid map width"

# define OPEN_ERROR					-1

# define WIN_TITLE					"FdF@hiabe"
# define WIN_HEIGHT					720
# define WIN_WIDTH					1280

# define DEFAULT_ZOOM				(0.25)
# define DEFAULT_HEIGHT_EMPHASIS	1

# define PI							(3.14159265358979323846264338327950288)
# define ANGLE_ISO					35

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
	t_display	*display;
	t_img		*img;
	t_map		*map;
	t_list		*data;
	bool		is_iso;
	double		zoom;
	double		points_distance;
	int			height_emphasis;
	int			delta_x;
	int			delta_y;
	int			rotate_x_angle;
	int			rotate_y_angle;
}	t_mlx;

// exit.c
void	error_exit(const char *msg, char *ptr, const int status);
void	clear_before_exit(t_info *info, const char *msg, const int n);

// args.c
int		check_args(int argc, char *argv[]);

// read.c
size_t	read_map(int fd, t_list **data);

// clear.c
void	clear_split_list(char **list);
void	clear_data(t_list *data);
void	clear_map_to_n(t_map *map, size_t n);
int		close_window(t_mlx *mlxs);

// parse.c
void	parse_map(t_info *info, size_t line_count);

// parse2.c
void	set_data_to_map(t_info *info, t_list *data, size_t i);

// display_map.c
void	display_map(t_info *info);

// image.c
void	my_mlx_pixel_put(t_img *img, int y, int x, int color);
void	set_image(t_mlx *mlxs);
void	draw_image(t_mlx *mlxs);

// draw_line.c
void	draw_line_right_down(t_mlx *mlxs, size_t x, size_t y);

// rotate.c
void	calc_and_rotate(t_mlx *mlxs, t_point *point, size_t x, size_t y);

#endif
