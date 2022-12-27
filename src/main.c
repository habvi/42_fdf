#include "fdf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	const int	fd = check_args(argc, argv);
	t_info		info;
	size_t		line_count;

	info.data = NULL;
	line_count = read_map(fd, &info.data);
	info.head = info.data;
	display_map(info.data, line_count);
	return (0);
}

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks ~");
// 	exit (1);
// }
