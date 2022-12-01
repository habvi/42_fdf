#include "fdf.h"
#include <stdio.h> // todo: printf -> ft_printf

void	check_args(int argc)
{
	if (argc != 2)
	{
		printf("%s\n", "Error: invalid arguments");
		exit (1);
	}
}

int	check_filepath(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDWR);
	if (errno)
	{
		printf("Error no.%d : %s\n", errno, strerror(errno));
		exit (errno);
	}
	return (fd);
}

void	read_map(int fd, t_list **map)
{
	char	*line;
	t_list	*node;
	size_t	line_count;

	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL) // errno
			break ;
		node = ft_lstnew(line);
		// todo: check map malloc error
		ft_lstadd_back(map, node);
		line_count++;
	}
	printf("%zu lines\n\n", line_count);
}

void	del(void *content)
{
	free(content);
}

void	clear_map(t_list **map)
{
	ft_lstclear(map, del);
}

void	print_lst_all(void *content)
{
	printf("%s", content);
}

void	debug_lst(t_list *lst)
{
	ft_lstiter(lst, print_lst_all);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_list	*map;

	check_args(argc);
	fd = check_filepath(argv[1]);
	map = NULL;
	read_map(fd, &map);
	debug_lst(map);
	clear_map(&map);
	return (0);
}
