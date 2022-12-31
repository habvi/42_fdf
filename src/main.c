#include "fdf.h"
#include <stdio.h>

static void	init_info(t_info *info, t_map *map)
{
	info->data = NULL;
	info->map = map;
}

int	main(int argc, char *argv[])
{
	t_info		info;
	t_map		map;
	const int	fd = check_args(argc, argv);
	size_t		line_count;

	init_info(&info, &map);
	line_count = read_map(fd, &(info.data));
	info.head = info.data;
	parse_map(&info, line_count);
	display_map(&info);
	return (0);
}

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks ~");
// 	exit (1);
// }
