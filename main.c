#include "fdf.h"
#include <stdio.h> // to do: printf -> ft_printf

size_t	read_map(int fd, t_list **data)
{
	char	*line;
	t_list	*node;
	size_t	line_count;
	t_list	*head;

	line_count = 0;
	head = *data;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		// remove '\n' here?
		node = ft_lstnew(line);
		// to do: check data malloc error, free head ~ now
		if (errno)
			return (0);
		if (line_count >= 2)
			data = &((*data)->next);
		ft_lstadd_back(data, node);
		// to do: all node keeps head
		line_count++;
	}
	return (line_count);
}

int	main(int argc, char *argv[])
{
	const int	fd = check_args(argc, argv);
	t_list		*data;
	size_t		line_count;

	data = NULL;
	line_count = read_map(fd, &data);
	// malloc fail
	// debug_lst(data, line_count); // to do: erase
	if (data == NULL) // empty file
		exit (0);
	draw_map(data, line_count);
	return (0);
}

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks ~");
// 	exit (1);
// }
