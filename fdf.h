#ifndef FDF_H
# define FDF_H

# include <fcntl.h> // open
// # include <unistd.h> // close, read, write
# include <stdlib.h> // malloc, free, exit
// # include <stdio.h> // perror
# include <string.h> // strerror
# include <errno.h>
# include <stdbool.h>

# include "libft.h"
# include "list.h"
# include "get_next_line.h"

typedef struct s_map
{
	size_t	width;
	size_t	height;
	int		**height_map;
	int		**color_map;
}	t_map;

// main.c
void	is_correct_extension(char *filepath);
int		check_filepath(char *filepath);
int		check_args(int argc, char *argv[]);
size_t	read_map(int fd, t_list **map);
void	clear_data(t_list **map);

void	debug_lst(t_list *lst, size_t line_count);

// draw_map.c
void	draw_map(t_list **map, size_t line_count);

#endif
