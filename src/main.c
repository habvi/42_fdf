#include <limits.h>
#include <unistd.h>
#include "fdf.h"

static void	init_info(t_info *info, t_map *map)
{
	info->head = NULL;
	info->tail = NULL;
	info->map = map;
	info->z_min = INT_MAX;
	info->z_max = INT_MIN;
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_map	map;
	size_t	line_count;
	uint8_t	error_code;

	error_code = 0;
	if (!check_args(argc, argv, &error_code))
		error_exit(error_code);
	init_info(&info, &map);
	// return error
	read_map(argv[1], &info, &line_count);
	// return error
	parse_map(&info, line_count);
	display_map(&info);
	return (SUCCESS);
}
