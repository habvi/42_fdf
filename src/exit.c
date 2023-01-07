#include "fdf.h"
#include "../libft/include/ft_printf.h"

// args, read
void	error_exit(const char *msg, void *ptr, const int status)
{
	ft_printf("Error: %s\n", msg);
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
