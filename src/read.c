#include <fcntl.h> // open
#include <string.h> // strerror
#include <errno.h>
#include "get_next_line.h"
#include "list.h"
#include "fdf.h"
#include "error.h"

static void	add_line_to_data(t_info *info, char *line, const size_t line_count)
{
	t_list	*node;

	node = ft_lstnew(line);
	if (node == NULL)
	{
		clear_data(info->head);
		error_exit(ERROR_MALLOC_FDF);
	}
	if (line_count >= 2)
		info->tail = info->tail->next;
	ft_lstadd_back(&info->tail, node);
}

static size_t	read_map_to_info(const int fd, t_info *info)
{
	size_t	line_count;
	char	*line;

	line_count = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_line_to_data(info, line, line_count);
		if (!line_count)
			info->head = info->tail;
		line_count++;
	}
	if (info->tail == NULL)
		error_exit(ERROR_EMPTY_FILE);
	return (line_count);
}

void	read_map(const char *filepath, t_info *info, size_t *line_count)
{
	int	fd;

	errno = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == OPEN_ERROR)
		error_exit_errno(strerror(errno));
	*line_count = read_map_to_info(fd, info);
	close(fd);
}
