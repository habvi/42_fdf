#include "fdf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	const int	fd = check_args(argc, argv);
	t_info		info;
	t_map		map;
	size_t		line_count;

	info.data = NULL;
	line_count = read_map(fd, &info.data);
	info.head = info.data;
	info.map = &map;
	parse_map(&info, line_count);
	display_map(&info);
	return (0);
}

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks ~");
// 	exit (1);
// }
