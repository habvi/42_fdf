#ifndef DEBUG_H
# define DEBUG_H

# include <fcntl.h> // open
// # include <unistd.h> // close, read, write
# include <stdlib.h> // malloc, free, exit
# include <stdio.h> // printf, perror
# include <string.h> // strerror
# include <errno.h>
# include <stdbool.h>

# include "fdf.h"

// main.c
void	debug_lst(t_list *lst, size_t line_count);

// draw_map.c
void	debug_split_list(char **list);

// display_map.c
void	debug_map(t_map *map);

#endif
