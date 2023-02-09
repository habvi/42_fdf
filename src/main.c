#include <limits.h>
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
	int		fd;
	t_info	info;
	t_map	map;
	size_t	line_count;

	check_args(argc, (const char **)argv);
	fd = open_file(argv[1]);
	init_info(&info, &map);
	line_count = read_map(fd, &info);
	parse_map(&info, line_count);
	display_map(&info);
	return (0);
}
