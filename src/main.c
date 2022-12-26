#include "fdf.h"

int	main(int argc, char *argv[])
{
	const int	fd = check_args(argc, argv);
	t_list		*data;
	size_t		line_count;

	data = NULL;
	line_count = read_map(fd, &data);
	display_map(data, line_count);
	return (0);
}

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks ~");
// 	exit (1);
// }
