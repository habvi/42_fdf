#include "fdf.h"

int	main(int argc, char *argv[])
{
	const int	fd = check_args(argc, argv);
	t_list		*data;
	size_t		line_count;
	char		*msg;

	data = NULL;
	line_count = read_map(fd, &data);
	// malloc fail
	// debug_lst(data, line_count); // to do: erase
	if (data == NULL) // empty file
	{
		msg = "empty file";
		error_and_exit(msg, NULL, EXIT_ERROR);
	}
	draw_map(data, line_count);
	return (0);
}

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks ~");
// 	exit (1);
// }
