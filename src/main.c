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

	check_args(argc, argv);
	init_info(&info, &map);
	read_map(argv[1], &info, &line_count);
	parse_map(&info, line_count);
	display_map(&info);
	return (SUCCESS);
}
