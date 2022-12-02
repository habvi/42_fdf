#include "fdf.h"
#include <stdio.h> // todo: printf -> ft_printf

void	is_correct_extension(char *filepath)
{
	const char	extension[] = ".fdf";
	size_t		len_extension;
	size_t		len_filepath;

	len_extension = ft_strlen(extension);
	len_filepath = ft_strlen(filepath);
	if (len_filepath <= len_extension)
	{
		printf("Error: invalid filepath\n");
		exit (errno);
	}
	while (len_extension)
	{
		len_extension--;
		len_filepath--;
		if (filepath[len_filepath] != extension[len_extension])
		{
			printf("Error: invalid file's extension\n");
			exit (errno);
		}
	}
}

int	check_filepath(char *filepath)
{
	int	fd;

	is_correct_extension(filepath);
	fd = open(filepath, O_RDWR);
	if (errno)
	{
		printf("Error no.%d : %s\n", errno, strerror(errno));
		exit (errno);
	}
	return (fd);
}

int	check_args(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
	{
		printf("Error: invalid number of arguments\n");
		exit (1);
	}
	fd = check_filepath(argv[1]);
	return (fd);
}

size_t	read_map(int fd, t_list **data)
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
		// remove '\n'
		node = ft_lstnew(line);
		// todo: check map malloc error
		ft_lstadd_back(data, node);
		line_count++;
	}
	return (line_count);
}

static void	del(void *content)
{
	free(content);
}

void	clear_data(t_list **data)
{
	ft_lstclear(data, del);
}

static void	print_list_content(void *content)
{
	printf("%s", content);
}

void	debug_lst(t_list *lst, size_t line_count)
{
	printf("%zu lines\n\n", line_count);
	ft_lstiter(lst, print_list_content);
}

int	main(int argc, char *argv[])
{
	const int	fd = check_args(argc, argv);
	t_list		*data;
	size_t		line_count;

	data = NULL;
	line_count = read_map(fd, &data);
	// debug_lst(data, line_count); // todo: erase
	if (data == NULL)  // empty file
		exit (0);
	draw_map(&data, line_count);
	return (0);
}

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks ~");
// 	exit (1);
// }
