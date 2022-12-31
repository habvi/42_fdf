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
// # include "get_next_line.h"
// # include "minilibx/mlx.h"

# include "../libft/include/libft.h"
# include "../libft/include/list.h"
# include "../libft/include/get_next_line.h"
# include "../minilibx/mlx.h"

# define INVALID_MAP_MSG		"invalid map\n"
# define MALLOC_ERROR_MSG		"malloc\n"
# define WIN_WIDTH				1200
# define WIN_HEIGHT				800
# define PI						(3.14159265358979323846264338327950288)
# define START_MARGIN			50
# define SHIFT_X				400
# define SHIFT_Y				300
# define PIXEL_SIZE				30
# define HEIGHT_MAGNIFICATION	2

# define OPEN_ERROR				-1

typedef enum e_status {
	SUCCESS = 0,
	ERROR = 1
}	t_status;

typedef enum e_key {
	// KEY_UP = 65362,
	// KEY_DOWN = 65364,
	// KEY_LEFT = 65361,
	// KEY_RIGHT = 65363,
	// KEY_ONE = 49,
	// KEY_TWO = 50,
	KEY_ESC = 65307
}	t_key;

typedef enum e_mouse {
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 3,
	// MOUSE_UP = 4,
	// MOUSE_DOWN = 5
}	t_mouse;

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

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_xy {
	int	x;
	int	y;
}	t_xy;

typedef struct s_point {
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_mlx {
	t_display	*display;
	t_img_data	*img;
	t_map		*map;
	t_list		*data;
}	t_mlx;

// exit.c
void	print_msg_and_exit(const char *msg, char *ptr, const int status);
void	clear_and_exit(t_info *info, const char *msg, const int n);

// args.c
int		check_args(int argc, char *argv[]);

// read.c
size_t	read_map(int fd, t_list **data);

// clear.c
void	clear_split_list(char **list);
void	clear_data(t_list *data);
void	clear_map_to_n(t_map *map, size_t n);
int		close_window(int keycode, t_mlx *mlxs);

// parse.c
void	parse_map(t_info *info, size_t line_count);

// parse2.c
void	set_data_to_map(t_info *info, t_list *data, size_t i);

// display_map.c
void	display_map(t_info *info);

#endif
