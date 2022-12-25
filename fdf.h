#ifndef FDF_H
# define FDF_H

# include <fcntl.h> // open
// # include <unistd.h> // close, read, write
# include <stdlib.h> // malloc, free, exit
// # include <stdio.h> // perror
# include <string.h> // strerror
# include <errno.h> // to do: fix
# include <stdbool.h>

# include "libft.h"
# include "list.h"
# include "get_next_line.h"
# include "minilibx/mlx.h"

# define INVALID_MAP_MSG		"Error: invalid map\n"
# define MALLOC_ERROR_MSG		"Error: malloc\n"
# define WIN_WIDTH				1200
# define WIN_HEIGHT				800
# define PI						(3.14159265358979323846264338327950288)
# define START_MARGIN			50
# define SHIFT_X				400
# define SHIFT_Y				300
# define PIXEL_SIZE				30
# define HEIGHT_MAGNIFICATION	2

# define EXIT_SUCCESS			0
# define EXIT_ERROR				1
# define OPEN_ERROR				-1
# define KEY_ESC				65307

typedef struct s_display {
	void	*mlx_p;
	void	*window_p;
}	t_display;

typedef struct s_map
{
	size_t	width;
	size_t	height;
	int		**height_map;
	int		**color_map;
}	t_map;

# include "debug.h" // to do: erase

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_for_exit {
	t_display	*display;
	t_map		*map;
	t_list		*data;
	t_img_data	*img;
}	t_for_exit;

// main.c
size_t	read_map(int fd, t_list **data);

// args.c
int		check_args(int argc, char *argv[]);

// draw_map.c
void	draw_map(t_list *data, size_t line_count);

// clear.c
void	clear_split_list(char **list);
void	clear_data(t_list *data);
void	clear_map_to_n(t_map *map, size_t n);
int		close_window(int keycode, t_for_exit *for_exit);

// display_map.c
void	display_map(t_map *map, t_for_exit *for_exit);

#endif
