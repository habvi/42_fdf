#include "fdf.h"
#include <stdio.h> // to do: printf -> ft_printf

// args, read
void	error_exit(const char *msg, void *ptr, const int status)
{
	printf("Error: %s\n", msg);
	if (ptr)
		free(ptr);
	exit(status);
}

// parse, parse2
void	clear_before_exit(const t_info *info, const char *msg, const size_t n)
{
	clear_data((t_list *)info->head);
	clear_map_to_n(info->map, n);
	error_exit(msg, NULL, EXIT_FAILURE);
}
