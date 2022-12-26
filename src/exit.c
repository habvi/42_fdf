#include "fdf.h"
#include <stdio.h> // to do: printf -> ft_printf

// main, args, read
void	print_msg_and_exit(const char *msg, char *ptr, const int status)
{
	printf("Error: %s\n", msg);
	if (ptr)
		free(ptr);
	exit (status);
}

// parse
void	clear_and_exit(t_map *map, const t_list *data, const char *msg, const int n)
{
	clear_data((t_list *)data);
	clear_map_to_n(map, n);
	print_msg_and_exit(msg, NULL, EXIT_ERROR);
}
